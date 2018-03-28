#Stack: 
#a: 128
#b: 132
#c: 136
#d: 140
#e: 144
#f: 148
	.text
	.align	2
	.globl	g
	.set	nomips16
	.set	nomicromips
	.ent	g
	.type	g, @function
g:
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

	sw		$4, 128($fp)
	sw		$5, 132($fp)
	sw		$6, 136($fp)
	sw		$7, 140($fp)
#compiling function body
	li		$2, 10
	lw		$8, 128($fp)
	subu	$2, $2, $8
	lw		$3, 132($fp)
	subu	$2, $2, $3

#deallocating stack
	move	$sp, $fp
	lw		$fp, 120($sp)
	lw		$ra, 124($sp)
	addiu	$sp, $sp, 128
	j		$ra
	nop

	.set	macro
	.set	reorder
	.end	g
	.size	g, .-g
#Stack: 
#a: 116
#b: 112
#c: 108
#d: 104
#e: 100
#f: 96
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

#compiling function body
	li		$2, 1
	sw		$2, 116($fp)
	li		$2, 2
	sw		$2, 112($fp)
	li		$2, 3
	sw		$2, 108($fp)
	li		$2, 4
	sw		$2, 104($fp)
	li		$2, 5
	sw		$2, 100($fp)
	li		$2, 6
	sw		$2, 96($fp)
	li		$4, 1
	lw		$5, 112($fp)
	li		$6, 3
	lw		$7, 104($fp)
	li		$2, 5
	sw		$2, 16($sp)
	lw		$2, 96($fp)
	sw		$2, 20($sp)
	jal	g
	nop

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
