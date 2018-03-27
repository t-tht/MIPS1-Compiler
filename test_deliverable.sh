#!/bin/bash

if [[ "$1" != "" ]] ; then
    compiler="$1"
else
    compiler="bin/c_compiler"
fi

have_compiler=0
if [[ ! -f bin/c_compiler ]] ; then
    >&2 echo "Warning : cannot find compiler at path ${compiler}. Only checking C reference against python reference."
    have_compiler=1
fi

input_dir="test_deliverable/test_cases"

working="tmp/test_deliverable"
mkdir -p ${working}

for i in ${input_dir}/*.c ; do
NAME=$(echo $i | sed -E -e "s|${input_dir}/([^.]+)[.]c|\1|g");
TESTDIR= ${input_dir}/$NAME.c
echo "name:" +$TESTDIR

    # Compile the driver
    mips-linux-gnu-gcc -static $i -o ${working}/${NAME}_driver.o 2> ${working}/${NAME}_driver.compile.stderr
if [[ $? -ne 0 ]] ; then
echo "mips-linux-gnu-gcc -static $i -o ${working}/${NAME}_driver.o 2> ${working}/${NAME}_driver.compile.stderr"
echo "$NAME, Result, $?, Fail, Cannot compile driver"
continue
fi
echo "1st"
    
    # Compile the function
    cat $TESTDIR | $compiler > ${working}/$NAME.s  2> ${working}/${NAME}.compile.stderr
echo "2nd"
    if [[ $? -ne 0 ]] ; then
    echo "$NAME, Fail, No C compiler/translator"
    continue
    fi

    # Run the DUT MIPS version
        mips-linux-gnu-gcc -static ${working}/$NAME.s ${working}/${NAME}_driver.o -o ${working}/${NAME}.elf 2> ${working}/${NAME}.link.stderr
#echo "3rd"
        if [[ $? -ne 0 ]] ; then
            echo "$NAME, Fail, Cannot compile"
            continue
        fi

    #run the mips Binary
        qemu-mips ${working}/${NAME}.elf
        GOT_M_OUT=$?
#echo "4th"

    if [[ $GOT_M_OUT -ne 0 ]] ; then
        echo "$NAME, Fail, test returned $GOT_M_OUT"
    else
        echo "$NAME, Pass"
    fi
done
