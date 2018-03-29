	.globl	x
	.data
	.align	2
	.type	x, @object
	.size	x, 4
a:
		.word	1


	.text
	.align	2
	.globl	global
	.set	nomips16
	.set	nomicromips
	.ent	global
	.type	global, @function
global:
	.frame	$fp, 128, $ra
	.mask	0x40000000, -4
	.fmask	0x00000000, 0
	.set	noreorder
	.set	nomacro

#allocate stack
	addiu	$sp, $sp, -128
	sw		$ra, 124($sp)
	sw		$fp, 120($sp)
	move	$fp, $sp

	lui		$2, %hi(x)
	lw		$2, %lo(x)($2)

#deallocating stack
	move	$sp, $fp
	lw		$fp, 120($sp)
	lw		$ra, 124($sp)
	addiu	$sp, $sp, 128
	j		$ra
	nop

#Stack : 
#Local Variable : 

#deallocating stack
	move	$sp, $fp
	lw		$fp, 120($sp)
	lw		$ra, 124($sp)
	addiu	$sp, $sp, 128
	j		$ra
	nop

	.set	macro
	.set	reorder
	.end	global
	.size	global, .-global
#Stack : 
#Local Variable : 
#compile finished
#Global Variables : 
#x: 1
