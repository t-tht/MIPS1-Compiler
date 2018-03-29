

	.text
	.align	2
	.globl	a
	.set	nomips16
	.set	nomicromips
	.ent	a
	.type	a, @function
a:
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

	sw		$4, 128($fp)
	lw		$2, 128($fp)
	li		$3, 1
	addu	$2, $2, $3

#deallocating stack
	move	$sp, $fp
	lw		$fp, 120($sp)
	lw		$ra, 124($sp)
	addiu	$sp, $sp, 128
	j		$ra
	nop

	.set	macro
	.set	reorder
	.end	a
	.size	a, .-a
#Stack : 
#x: 128
#Local Variable : 


	.text
	.align	2
	.globl	b
	.set	nomips16
	.set	nomicromips
	.ent	b
	.type	b, @function
b:
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

	sw		$4, 128($fp)
	lw		$4, 128($fp)
	li		$2, 1
	addu	$4, $4, $2
	jal		a
	nop

#deallocating stack
	move	$sp, $fp
	lw		$fp, 120($sp)
	lw		$ra, 124($sp)
	addiu	$sp, $sp, 128
	j		$ra
	nop

	.set	macro
	.set	reorder
	.end	b
	.size	b, .-b
#Stack : 
#x: 128
#Local Variable : 


	.text
	.align	2
	.globl	main
	.set	nomips16
	.set	nomicromips
	.ent	main
	.type	main, @function
main:
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

	li		$4, 2
	jal		b
	nop
	li		$4, 2
	jal		a
	nop
	move	$3, $2
	addu	$2, $2, $3

#deallocating stack
	move	$sp, $fp
	lw		$fp, 120($sp)
	lw		$ra, 124($sp)
	addiu	$sp, $sp, 128
	j		$ra
	nop

	.set	macro
	.set	reorder
	.end	main
	.size	main, .-main
#Stack : 
#Local Variable : 
#compile finished
#Global Variables : 
