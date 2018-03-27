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
	li		$9, 2
	mult	$2, $9
	mflo	$2
	li		$8, 3
	li		$11, 4
	mult	$8, $11
	mflo	$8
	li		$10, 5
	li		$13, 6
	mult	$10, $13
	mflo	$10
	li		$12, 7
	li		$14, 8
	mult	$12, $14
	mflo	$12
	addu	$10, $10, $12
	addu	$8, $8, $10
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
#Occupied Registers
#0: 
#1: 
#2: 
#3: 
#4: 
#5: 
#6: 
#7: 
#8: yes
#9: yes
#10: yes
#11: yes
#12: yes
#13: yes
#14: yes
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
