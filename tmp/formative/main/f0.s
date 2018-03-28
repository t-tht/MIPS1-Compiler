

	.text
	.align	2
	.globl	function
	.set	nomips16
	.set	nomicromips
	.ent	function
	.type	function, @function
function:
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
	li		$2, 10

#deallocating stack
	move	$sp, $fp
	lw		$fp, 120($sp)
	lw		$ra, 124($sp)
	addiu	$sp, $sp, 128
	j		$ra
	nop

	.set	macro
	.set	reorder
	.end	function
	.size	function, .-function
#Stack : 
#Local Variable : 
#compile finished
#Global Variables : 
