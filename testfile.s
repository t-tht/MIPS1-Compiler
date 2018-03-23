	.text
	.align	2
	.globl	main
	.set	nomips16
	.set	nomicromips
	.ent	main
	.type	main, @function
main:
	.frame	$fp, 128, $ra
	.mask	0x40000000, -4
	.fmask	0x00000000, 0
	.set	noreorder
	.set	nomacro

#allocate stack
	addiu	$sp, $sp, -128
	sw		$ra, 124($sp)
	sw		$fp, 120($sp)
	move	$fp, $sp

#pushing param onto stack
	sw		$4, 128($fp)
	sw		$8, 132($fp)
	sw		$12, 136($fp)
	sw		$16, 140($fp)

#compiling function body
	li		$2, 10
	sw		$2, 4294967295($fp)
	li		$2, 20
	sw		$2, 4294967295($fp)
	addu	$2, $2, $8

#deallocating stack
	move	$sp, $fp
	lw		$fp, 120($sp)
	lw		$ra, 124($sp)
	addiu	$sp, $sp, 128
	j		$ra
	nop

	.set	macro
	.set	reorder
	.end	main
	.size	main, .-main
