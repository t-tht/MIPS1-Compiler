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

#compiling function body
	li		$2, 1
	li		$8, 2
	mult	$2, $8
	mflo	$2
	li		$3, 3
	li		$8, 4
	mult	$3, $8
	mflo	$3
	li		$2, 5
	li		$8, 6
	mult	$2, $8
	mflo	$2
	li		$3, 7
	li		$2, 8
	mult	$3, $2
	mflo	$3
	addu	$2, $2, $3
	addu	$3, $3, $2
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
