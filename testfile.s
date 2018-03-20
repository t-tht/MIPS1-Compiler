	.text
	.align	2
	.globl	main
	.set	nomips16
	.set	nomicromips
	.ent	main
	.type	main, @function
main:
		#f size: 16
	.frame	$fp, 16, $ra
	.mask	0x40000000, -4
	.fmask	0x00000000, 0
	.set	noreorder
	.set	nomacro

	addiu	$sp, $sp, -16
	sw		$fp, 12($sp)
	move	$fp, $sp

	sw		$4, 16($fp)
	sw		$5, 20($fp)
	sw		$6, 24($fp)
	sw		$7, 28($fp)

	li		$2, 10
	li		$8, 20
	li		$9, 30
	addu	$8, $8, $9
	addu	$2, $2, $8

	move	$sp, $fp
	lw		$fp, 12($sp)
	addiu	$sp, $sp, 16
	j		$ra
	nop

	.set	macro
	.set	reorder
	.end	main
	.size	main, .-main
