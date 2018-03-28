#!/bin/bash


compiler="bin/c_compiler"


have_compiler=0
if [[ ! -f bin/c_compiler ]] ; then
    >&2 echo "Warning : cannot find compiler at path ${compiler}. Only checking C reference against python reference."
    have_compiler=1
fi

input_dir=$1

working="tmp/random"
mkdir -p ${working}


REF_C_OUT=$2

    if [[ ${have_compiler} -eq 0 ]] ; then

        # Run the DUT MIPS version
        $compiler --compile $1 -o ${working}/$base.s
        mips-linux-gnu-gcc -static ${working}/$base.s -o ${working}/$base-s-got

        #run the mips Binary
        qemu-mips ${working}/$base-s-got
        GOT_P_OUT=$?


    fi

    if [[ ${have_compiler} -ne 0 ]] ; then
        echo "$1, Fail, No C compiler/translator"
    elif [[ $REF_C_OUT -ne $GOT_P_OUT ]] ; then
        echo "$1, Fail, Expected ${REF_C_OUT}, got ${GOT_P_OUT}"
    else
        echo "$1, Pass"
    fi

