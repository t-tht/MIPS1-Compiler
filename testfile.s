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

	li		$2, 10

	move	$sp, $fp
	lw		$fp, 12($sp)
	addiu	$sp, $sp, 16
	j		$ra
	nop

	.set	macro
	.set	reorder
	.end	main
	.size	main, .-main
