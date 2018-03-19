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
	sw		$31, 4($sp)
	sw		$fp, 0($sp)
	move	$fp, $sp
	sw		$4, 12($fp)
	sw		$5, 16($fp)
	sw		$6, 20($fp)
	sw		$7, 24($fp)
	li		$2, 10
	move	$sp, $fp
	lw		$fp, 4($sp)
	addiu	$sp, $sp, 8
	j		$31
	nop

	.set	macro
	.set	reorder
	.end	main
	.size	main, .-main
