	.file	1 "f0.c"
	.section .mdebug.abi32
	.previous
	.nan	legacy
	.module	fp=xx
	.module	nooddspreg
	.abicalls
	.text
	.align	2
	.globl	main
$LFB0 = .
	.cfi_startproc
	.set	nomips16
	.set	nomicromips
	.ent	main
	.type	main, @function
main:
	.frame	$fp,8,$31		# vars= 0, regs= 1/0, args= 0, gp= 0
	.mask	0x40000000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	addiu	$sp,$sp,-8
	.cfi_def_cfa_offset 8
	sw	$fp,4($sp)
	.cfi_offset 30, -4
	move	$fp,$sp
	.cfi_def_cfa_register 30
	li	$2,10			# 0xa
	move	$sp,$fp
	.cfi_def_cfa_register 29
	lw	$fp,4($sp)
	addiu	$sp,$sp,8
	.cfi_restore 30
	.cfi_def_cfa_offset 0
	j	$31
	nop

	.set	macro
	.set	reorder
	.end	main
	.cfi_endproc
$LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.9) 5.4.0 20160609"
