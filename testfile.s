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
	li		$2, 2
	sw		$2, 0($fp)
	li		$2, 4
	sw		$2, 4($fp)
	li		$2, 6
	sw		$2, 8($fp)
	li		$2, 8
	sw		$2, 12($fp)
	lw		$2, 0($fp)
	lw		$3, 4($fp)
	addu	$2, $2, $3
	sw		$2, 16($fp)
	lw		$2, 8($fp)
	lw		$3, 12($fp)
	lw		$8, 16($fp)
	addu	$3, $3, $8
	addu	$2, $2, $3
	sw		$2, 20($fp)
	lw		$2, 16($fp)
	lw		$3, 20($fp)
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
	.end	main
	.size	main, .-main

#Occupied Registers
#0: 
#1: 
#2: 
#3: 
#4: 
#5: 
#6: 
#7: 
#8: 
#9: 
#10: 
#11: 
#12: 
#13: 
#14: 
#15: 
#16: 
#17: 
#18: 
#19: 
#20: 
#21: 
#22: 
#23: 
#24: 
#25: 
#26: 
#27: 
#28: 
#29: 
#30: yes
#31: 
