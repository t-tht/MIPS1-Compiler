	.text
	.align	2
	.globl	main
	.set	nomips16
	.set	nomicromips
	.ent	main
	.type	main, @function
main:
	.frame	$fp, 32, $ra
	.mask	0x40000000, -4
	.fmask	0x00000000, 0
	.set	noreorder
	.set	nomacro

	addiu	$sp, $sp, -32
	sw		$ra, 28($sp)
	sw		$fp, 24($sp)
	move	$fp, $sp

	sw		$4, 28($fp)
	sw		$5, 32($fp)
	sw		$6, 36($fp)
	sw		$7, 40($fp)
#28
#32
#36
#40
	li		$2, 10

	move	$sp, $fp
	lw		$fp, 28($sp)
	addiu	$sp, $sp, 32
	j		$ra
	nop

	.set	macro
	.set	reorder
	.end	main
	.size	main, .-main
