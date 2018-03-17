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
	sw	$fp, 4($sp)
	move	$fp, $sp
	li	$2, 1
	li	$9, 2
	mult	$2, $9
	mflo	$2
	li	$8, 3
	li	$11, 4
	mult	$8, $11
	mflo	$8
	li	$10, 5
	li	$13, 6
	mult	$10, $13
	mflo	$10
	li	$12, 7
	li	$14, 8
	mult	$12, $14
	mflo	$12
	addu	$10, $10, $12
	addu	$8, $8, $10
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
