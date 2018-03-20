	.text
	.align	2
	.globl	main
	.set	nomips16
	.set	nomicromips
	.ent	main
	.type	main, @function
main:
	.frame	$fp, 8, $31
	.mask	0x40000000, -4
	.fmask	0x00000000, 0
	.set	noreorder
	.set	nomacro

	addiu	$sp, $sp, -8
	sw		$fp, 4($sp)
	move	$fp, $sp

	sw		$4, 8($fp)
	sw		$5, 12($fp)
	sw		$6, 16($fp)
	sw		$7, 20($fp)

	li		$2, 15

	move	$sp, $fp
	lw		$fp, 4($sp)
	addiu	$sp, $sp, 8
	j		$31
	nop

	.set	macro
	.set	reorder
	.end	main
	.size	main, .-main
