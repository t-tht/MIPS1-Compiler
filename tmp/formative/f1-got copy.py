int main(){ return f();}
int f(){ if(3<2){ return 5;} return 10;}
    .text
    .globl    main
    .ent    main
main:
    addiu    $sp,$sp,-32
    sw    $31,28($sp)
    sw    $fp,24($sp)
    move    $fp,$sp
    .option pic0
    jal    f
    nop
    
    .option    pic2
    move    $8,$2
    move    $2,$8
    move    $sp,$fp
    lw    $31,28($sp)
    lw    $fp,24($sp)
    addiu    $sp,$sp,32
    j    $31
    nop
    
    move    $sp,$fp
    lw    $31,28($sp)
    lw    $fp,24($sp)
    addiu    $sp,$sp,32
    j    $31
    nop
    .end    main
    
    .globl    f
    .ent    f
f:
    addiu    $sp,$sp,-64
    sw    $31,60($sp)
    sw    $fp,56($sp)
    move    $fp,$sp
    li    $8,3
    li    $9,2
    bge    $8,$9,flag101
    li    $8,5
    move    $2,$8
    move    $sp,$fp
    lw    $31,60($sp)
    lw    $fp,56($sp)
    addiu    $sp,$sp,64
    j    $31
    nop

flag101:
    li    $8,10
    move    $2,$8
    move    $sp,$fp
    lw    $31,60($sp)
    lw    $fp,56($sp)
    addiu    $sp,$sp,64
    j    $31e
    nop
    
    move    $sp,$fp
    lw    $31,60($sp)
    lw    $fp,56($sp)
    addiu    $sp,$sp,64
    j    $31
    nop
    .end    f


