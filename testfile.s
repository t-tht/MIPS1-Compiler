	.text
	.align	2
	.globl	f
	.set	nomips16
	.set	nomicromips
	.ent	f
	.type	f, @function
f:
	.frame	$fp, 16, $ra
	.mask	0x40000000, -4
	.fmask	0x00000000, 0
	.set	noreorder
	.set	nomacro

	addiu	$sp, $sp, -16
	sw		$ra, 12($sp)
	sw		$fp, 8($sp)
	move	$fp, $sp

	li		$2, 10

	move	$sp, $fp
	lw		$fp, 12($sp)
	addiu	$sp, $sp, 16
	j		$ra
	nop

	.set	macro
	.set	reorder
	.end	f
	.size	f, .-f
	.text
	.align	2
	.globl	main
	.set	nomips16
	.set	nomicromips
	.ent	main
	.type	main, @function
main:
	.frame	$fp, 80, $ra
	.mask	0x40000000, -4
	.fmask	0x00000000, 0
	.set	noreorder
	.set	nomacro

	addiu	$sp, $sp, -80
	sw		$ra, 76($sp)
	sw		$fp, 72($sp)
	move	$fp, $sp

	jal	f
	nop
	move	$2, $2

	move	$sp, $fp
	lw		$fp, 76($sp)
	addiu	$sp, $sp, 80
	j		$ra
	nop

	.set	macro
	.set	reorder
	.end	main
	.size	main, .-main
