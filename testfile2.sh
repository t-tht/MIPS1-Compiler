make clean;
make all;
mips-linux-gnu-gcc -c testfile_driver.c -o testfile_driver.o
bin/c_compiler -S testfile.c -c testfile.s;
mips-linux-gnu-gcc -static testfile.s testfile_driver.o -o test.elf;
qemu-mips test.elf;
echo $?;
