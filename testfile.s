	.text
	.align	2
	.globl	main
	.set	nomips16
	.set	nomicromips
	.ent	main
	.type	main, @function
main:
		#f size: 32
	.frame	$fp, 32, $ra
	.mask	0x40000000, -4
	.fmask	0x00000000, 0
	.set	noreorder
	.set	nomacro

	addiu	$sp, $sp, -32
	sw		$fp, 28($sp)
	move	$fp, $sp

	sw		$4, 32($fp)
	sw		$5, 36($fp)
	sw		$6, 40($fp)
	sw		$7, 44($fp)

	li		$2, 10
	li		$8, 20
	li		$9, 30
	addu	$8, $8, $9
	addu	$2, $2, $8

	move	$sp, $fp
	lw		$fp, 28($sp)
	addiu	$sp, $sp, 32
	j		$ra
	nop

	.set	macro
	.set	reorder
	.end	main
	.size	main, .-main
