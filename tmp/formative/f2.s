	.text
	.align	2
<<<<<<< HEAD
=======
	.globl	f
	.set	nomips16
	.set	nomicromips
	.ent	f
	.type	f, @function
f:
	.frame	$fp, 24, $31
	.mask	0x40000000, -4
	.fmask	0x00000000, 0
	.set	noreorder
	.set	nomacro
	addiu	$sp, $sp, -8
	sw	$fp, 4($sp)
	move	$fp, $sp
	li	$2, 10
	move	$sp, $fp
	movz	$31, $31, $0
	lw	$fp, 4($sp)
	addiu	$sp, $sp, 8
	j	$31
	nop

	.set	macro
	.set	reorder
	.end	f
	.size	f, .-f
	.text
	.align	2
>>>>>>> master
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
<<<<<<< HEAD
	li	$2, 10
	li	$8, 10
	li	$9, 2
	mult	$8, $9
	mflo	$8
	addu	$2, $2, $8
=======
	.option	pic0
	jal	f
	nop
	move	$2, $2
>>>>>>> master
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
