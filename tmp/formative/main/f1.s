	.text
	.align	2
	.globl	main
	.set	nomips16
	.set	nomicromips
	.ent	main
	.type	main, @function
main:
	.frame	$fp, 24, $31
	.mask	0x40000000, -4
	.fmask	0x00000000, 0
	.set	noreorder
	.set	nomacro
	addiu	$sp, $sp, -8
	sw	$fp, 4($sp)
	move	$fp, $sp
	li	$2, 10
	li	$8, 10
	addu	$2, $2, $8
	move	$sp, $fp
	movz	$31, $31, $0
	lw	$fp, 4($sp)
	addiu	$sp, $sp, 8
	j	$31
	nop

	.set	macro
	.set	reorder
	.end	main
	.size	main, .-main
