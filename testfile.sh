make clean;
make all;
bin/c_compiler -S testfile.c -c testfile.s;
mips-linux-gnu-gcc -static testfile.s -o test;
qemu-mips test;
echo $?;

