#!/bin/bash

#SBATCH --job-name=submit-extrae.sh
#SBATCH -D .
#SBATCH --output=submit-extrae.sh.o%j
#SBATCH --error=submit-extrae.sh.e%j

USAGE="\n USAGE: ./submit-omp.sh prog numthreads \n
        prog        -> Program name\n
        numthreads  -> Number of threads in parallel execution\n"

if (test $# -lt 2 || test $# -gt 2)
then
        echo -e $USAGE
        exit 0
fi

PROG=$1
make $PROG

HOST=$(echo $HOSTNAME | cut -f 1 -d'.')

export OMP_NUM_THREADS=$2

export LD_PRELOAD=${EXTRAE_HOME}/lib/libomptrace.so
./$PROG -h -i 10000 -w 320
unset LD_PRELOAD

mpi2prv -f TRACE.mpits -o tracetocut.prv -e $PROG -paraver
rm -rf TRACE.mpits set-0 TRACE.sym >& /dev/null

#Finding the trace limits as delimited by the initial and final "fake" parallel region
start=$(grep 60000001 tracetocut.prv | head -n2 | tail -n1 | cut -d ":" -f 6)
start=$((start+1))
end=$(grep 60000001 tracetocut.prv | tail -n2 | head -n1 | cut -d ":" -f 6)
end=$((end-1))

#Generating the xml file for cutting the original trace
cp $BASICANALYSIS_HOME/.cutter.xml cutter.xml
sed -i -e "s/LLL/$start/g" cutter.xml
sed -i -e "s/UUU/$end/g" cutter.xml

#Cutting the trace for proper analysis
paramedir tracetocut.prv -c cutter.xml -o ${PROG}-${OMP_NUM_THREADS}-${HOST}.prv
rm tracetocut.*
rm cutter.xml
