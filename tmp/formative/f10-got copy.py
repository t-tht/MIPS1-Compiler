int main(){ return f();}
int f(){ if(3<2){ return 5;} return 10;}
    .text
    .align    2
    .globl    main
    .set    nomips16
    .set    nomicromips
    .ent    main
    .type    main, @function
main:
    .frame    $fp, 128, $ra
    .mask    0x40000000, -4
    .fmask    0x00000000, 0
    .set    noreorder
    .set    nomacro
    
    #allocate stack
    addiu    $sp, $sp, -128
    sw        $ra, 124($sp)
    sw        $fp, 120($sp)
    move    $fp, $sp
    
    jal    f
    nop
    
    #deallocating stack
    move    $sp, $fp
    lw        $fp, 120($sp)
    lw        $ra, 124($sp)
    addiu    $sp, $sp, 128
    j        $ra
    nop
    
    .set    macro
    .set    reorder
    .end    main
    .size    main, .-main
    #Stack :
    #Local Variable :
    
    
    .text
    .align    2
    .globl    f
    .set    nomips16
    .set    nomicromips
    .ent    f
    .type    f, @function
f:
    .frame    $fp, 128, $ra
    .mask    0x40000000, -4
    .fmask    0x00000000, 0
    .set    noreorder
    .set    nomacro
    
    #allocate stack
    addiu    $sp, $sp, -128
    sw        $ra, 124($sp)
    sw        $fp, 120($sp)
    move    $fp, $sp
    
    #if statement--start
    li        $2, 3
    li        $3, 2
    bge    $2, $3, exit1
    li        $2, 5

exit1:
    li        $2, 10
    
    #deallocating stack
    move    $sp, $fp
    lw        $fp, 120($sp)
    lw        $ra, 124($sp)
    addiu    $sp, $sp, 128
    j        $ra
    nop
    
    .set    macro
    .set    reorder
    .end    f
    .size    f, .-f
#Stack :
#Local Variable :
#compile finished
#Global Variables :

