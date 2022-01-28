USAGE="\n USAGE: ./run_tareador.sh prog options \n
        prog        -> Tareador program name \n
        options     -> Tareador options: -d -h ... \n"

if (test $# -eq 0)
then
        echo -e $USAGE
        exit 0
fi

filename=$1
shift
make $filename

options=
# Loop until all Tareador parameters are used up
while [ "$1" != "" ]; do
    options+=$1
    options+=" "
    shift
done

rm -rf .tareador_precomputed_$filename
tareador_gui.py --llvm --lite $filename -b "-w 8 $options"
