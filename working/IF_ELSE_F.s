

	.text
	.align	2
	.globl	ifelsef
	.set	nomips16
	.set	nomicromips
	.ent	ifelsef
	.type	ifelsef, @function
ifelsef:
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
#if statement--start
	lw		$2, 128($fp)
	li		$3, 2
	bne		$2, $3, exit1

	lw		$2, 128($fp)

#deallocating stack
	move	$sp, $fp
	lw		$fp, 120($sp)
	lw		$ra, 124($sp)
	addiu	$sp, $sp, 128
	j		$ra
	nop

	j	escape1

exit1:
	li		$2, 1

#deallocating stack
	move	$sp, $fp
	lw		$fp, 120($sp)
	lw		$ra, 124($sp)
	addiu	$sp, $sp, 128
	j		$ra
	nop


escape1:

#deallocating stack
	move	$sp, $fp
	lw		$fp, 120($sp)
	lw		$ra, 124($sp)
	addiu	$sp, $sp, 128
	j		$ra
	nop

	.set	macro
	.set	reorder
	.end	ifelsef
	.size	ifelsef, .-ifelsef
#compile finished
#Global Variables : 
