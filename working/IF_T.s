

	.text
	.align	2
	.globl	ift
	.set	nomips16
	.set	nomicromips
	.ent	ift
	.type	ift, @function
ift:
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
	sw		$5, 132($fp)
#if statement--start
	lw		$2, 128($fp)
	lw		$3, 132($fp)
	bne		$2, $3, exit1

	li		$2, 0

#deallocating stack
	move	$sp, $fp
	lw		$fp, 120($sp)
	lw		$ra, 124($sp)
	addiu	$sp, $sp, 128
	j		$ra
	nop


exit1:
	li		$2, 1

#deallocating stack
	move	$sp, $fp
	lw		$fp, 120($sp)
	lw		$ra, 124($sp)
	addiu	$sp, $sp, 128
	j		$ra
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
	.end	ift
	.size	ift, .-ift
#compile finished
#Global Variables : 
