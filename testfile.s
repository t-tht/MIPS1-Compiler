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

	addiu	$sp, $sp, -128
	sw		$fp, 124($sp)
	move	$fp, $sp

	li		$0, 10
	li		$8, 20
	addu	$0, $0, $8
	addu	$0, $0, $9

	move	$sp, $fp
	lw		$fp, 124($sp)
	addiu	$sp, $sp, 128
	j		$ra
	nop

	.set	macro
	.set	reorder
	.end	main
	.size	main, .-main
