

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

	li		$2, 0
	sw		$2, 116($fp)
#for statement--start
	li		$2, 0
	sw		$2, 112($fp)

for1:
	lw		$2, 112($fp)
	li		$3, 7
	bge	$2, $3, exit1
	lw		$2, 112($fp)
	addiu	$2, $2, 1
	sw		$2, 112($fp)
	li		$2, 0
	sw		$2, 116($fp)

j	for1
exit1:
	lw		$2, 112($fp)

#deallocating stack
	move	$sp, $fp
	lw		$fp, 120($sp)
	lw		$ra, 124($sp)
	addiu	$sp, $sp, 128
	j		$ra
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
#compile finished
#Global Variables : 
