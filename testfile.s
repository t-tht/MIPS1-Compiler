

	.text
	.align	2
<<<<<<< HEAD
	.globl	ift
=======
	.globl	h
	.set	nomips16
	.set	nomicromips
	.ent	h
	.type	h, @function
h:
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

	li		$2, 20

#deallocating stack
	move	$sp, $fp
	lw		$fp, 120($sp)
	lw		$ra, 124($sp)
	addiu	$sp, $sp, 128
	j		$ra
	nop

	.set	macro
	.set	reorder
	.end	h
	.size	h, .-h
#Stack : 
#Local Variable : 


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
	lw		$2, 128($fp)

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
#Stack : 
#x: 128
#Local Variable : 


	.text
	.align	2
	.globl	func
	.set	nomips16
	.set	nomicromips
	.ent	func
	.type	func, @function
func:
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
	lw		$2, 128($fp)
	lw		$3, 132($fp)
	addu	$2, $2, $3
	lw		$3, 136($fp)
	addu	$2, $2, $3

#deallocating stack
	move	$sp, $fp
	lw		$fp, 120($sp)
	lw		$ra, 124($sp)
	addiu	$sp, $sp, 128
	j		$ra
	nop

	.set	macro
	.set	reorder
	.end	func
	.size	func, .-func
#Stack : 
#x: 128
#y: 132
#z: 136
#Local Variable : 


	.text
	.align	2
	.globl	main
>>>>>>> 06ec702e05564f4a893cfa8cf24713707433174b
	.set	nomips16
	.set	nomicromips
	.ent	ift
	.type	ift, @function
ift:
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

<<<<<<< HEAD
	sw		$4, 128($fp)
	sw		$5, 132($fp)
#if statement--start
	lw		$2, 128($fp)
	lw		$3, 132($fp)
	bne		$2, $3, exit1

	li		$2, 0

#deallocating stack
	move	$sp, $fp
	lw		$fp, 120($sp)
	lw		$ra, 124($sp)
	addiu	$sp, $sp, 128
	j		$ra
	nop

#Stack : 
#x: 128
#y: 132
#Local Variable : 

exit1:
	li		$2, 1

#deallocating stack
	move	$sp, $fp
	lw		$fp, 120($sp)
	lw		$ra, 124($sp)
	addiu	$sp, $sp, 128
	j		$ra
	nop

#Stack : 
#x: 128
#y: 132
#Local Variable : 
=======
	li		$2, 10
	sw		$2, 116($fp)
	lw		$4, 116($fp)
	jal		g
	nop
	move	$4, $2
	lw		$5, 116($fp)
	li		$6, 20
	jal		func
	nop
>>>>>>> 06ec702e05564f4a893cfa8cf24713707433174b

#deallocating stack
	move	$sp, $fp
	lw		$fp, 120($sp)
	lw		$ra, 124($sp)
	addiu	$sp, $sp, 128
	j		$ra
	nop

	.set	macro
	.set	reorder
	.end	ift
	.size	ift, .-ift
#Stack : 
<<<<<<< HEAD
#x: 128
#y: 132
#Local Variable : 
=======
#a: 116
#Local Variable : 
#a: 10
>>>>>>> 06ec702e05564f4a893cfa8cf24713707433174b
#compile finished
#Global Variables : 
