#!/bin/bash

#clear
if [[ -z "$1" ]]; then
COMPILER=bin/c_compiler
else
COMPILER=$1
fi

mkdir -p working

for DRIVER in test_deliverable/test_cases/*_driver.c ; do

NAME=$(basename $DRIVER _driver.c)
TESTCODE=test_deliverable/test_cases/$NAME.c

>&2 echo "Test case $NAME"
>&2 echo "Test case $TESTCODE"
# Compile driver with normal GCC
mips-linux-gnu-gcc -c $DRIVER -o working/${NAME}_driver.o
if [[ $? -ne 0 ]]; then
>&2 echo "                                                              ERROR : Couldn't compile driver program using GCC."
continue
fi

# Compile test function with compiler under test to assembly
$COMPILER -S $TESTCODE -o working/$NAME.s
if [[ $? -ne 0 ]]; then
>&2 echo "                                                              ERROR : Compiler returned error message."
continue
fi

# Link driver object and assembly into executable
mips-linux-gnu-gcc -static working/${NAME}.s working/${NAME}_driver.o -o working/${NAME}
if [[ $? -ne 0 ]]; then
>&2 echo "                                                              ERROR : Linker returned error message."
continue
fi

# Run the actual executable
qemu-mips working/${NAME}
result=$?
if [[ $result -ne 0 ]]; then
>&2 echo "                                                              ERROR : Testcase returned $result, but expected 0."
else
echo "                                                                  pass"
fi

done
