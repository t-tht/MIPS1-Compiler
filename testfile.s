	.globl	a
	.data
	.align	2
	.type	a, @object
	.size	a, 4
a:
		.word	5


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
#compiling function body
#assignment -- start
	lui		$2, %hi(a)
	li		$3, 6
	sw		$3, %lo(a)($2)
#assignment -- end
#binary expression--start
#variable primative--start
	lui		$3, %hi(a)
	lw		$2, %lo(a)($3)
#variable primative--end
#variable primative--start
	lw		$3, 128($fp)
#variable primative--end
	addu	$2, $2, $3
#binary expression--end

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
#i: 128
#Local Variable : 


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
	li		$4, 10
	jal	func
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
#Stack : 
#Local Variable : 
#compile finished
#Global Variables : 
#a: 5
