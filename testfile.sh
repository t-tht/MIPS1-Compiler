mips-linux-gnu-gcc -c -S testfile.c testfile.s;
mips-linux-gnu-gcc -static testfile.s -o testfile;
qemu-mips testfile;
echo $?;
