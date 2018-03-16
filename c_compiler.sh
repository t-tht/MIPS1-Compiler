#!/bin/bash


compiler="bin/c_compiler"


make clean
clear
make bin/c_compiler

have_compiler=0
if [[ ! -f bin/c_compiler ]] ; then
    >&2 echo "Warning : cannot find compiler at path ${compiler}. Only checking C reference against python reference."
    have_compiler=1
fi

input_dir="c_translator/formative"

working="tmp/compiler"
mkdir -p ${working}

for i in ${input_dir}/*.c ; do
    base=$(echo $i | sed -E -e "s|${input_dir}/([^.]+)[.]c|\1|g");
    
    # Compile the reference C version
    gcc $i -o $working/$base
    
    # Run the reference C version
    $working/$base
    REF_C_OUT=$?
    
    # Run the reference MIPS version
    mips-linux-gnu-gcc -static ${input_dir}/$base.s -o $base
    if [[ $? -ne 0 ]]; then
    >&2 echo "ERROR : Couldn't compile driver program using GCC."
    continue
    fi
    qemu-mips working/${NAME}
    REF_P_OUT=$?
    
    if [[ ${have_compiler} -eq 0 ]] ; then
        
        # Create the DUT python version by invoking the compiler with translation flags
        $compiler --translate $i -o ${working}/$base-got.py
        
        # Run the DUT python version
        python ${working}/$base-got.py
        GOT_P_OUT=$?
    fi
    
    if [[ $REF_C_OUT -ne $REF_P_OUT ]] ; then
        echo "$base, REF_FAIL, Expected ${REF_C_OUT}, got ${REF_P_OUT}"
    elif [[ ${have_compiler} -ne 0 ]] ; then
        echo "$base, Fail, No C compiler/translator"
    elif [[ $REF_C_OUT -ne $GOT_P_OUT ]] ; then
        echo "$base, Fail, Expected ${REF_C_OUT}, got ${GOT_P_OUT}"
    else
        echo "$base, Pass"
    fi
done
