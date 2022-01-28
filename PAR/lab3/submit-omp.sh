#!/bin/bash

#SBATCH --job-name=submit-omp.sh
#SBATCH -D .
#SBATCH --output=submit-omp.sh.o%j
#SBATCH --error=submit-omp.sh.e%j

USAGE="\n USAGE: ./submit-omp.sh prog numthreads \n
        prog        -> Program name\n
        numthreads  -> Number of threads in parallel execution\n"

if (test $# -lt 2 || test $# -gt 2)
then
        echo -e $USAGE
        exit 0
fi

make $1

HOST=$(echo $HOSTNAME | cut -f 1 -d'.')

export OMP_NUM_THREADS=$2

/usr/bin/time -o time-$1-$2-${HOST} ./$1 -h -i 10000 -o
