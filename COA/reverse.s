
#
# Author	: Praveen Gupta (16C0235)
# Date		: 26th August 2017
#


# data segment

.data
	str:	.asciiz		"HelloWorld!"
	len:	.word		11

# text segment
	
.text

.globl main
		
main: 	
	
	la $t0, str
	la $t1, len
	lw $t1, 0($t1)
	li $t2, 2
	div $t1, $t2	
	
	mflo $t2

	li $t6, 0
	li $t9, 1
	add $t6, $t0, $t1
	sub $t6 $t6, $t9
	 
	li $t3, 0
	
loop:
	beq $t2, $t3 out
	lb $t4, 0($t0)
	lb $t5, 0($t6)
	sb $t5, 0($t0)
	sb $t4, 0($t6)
	addi $t3, $t3, 1
	addi $t0, $t0, 1
	sub $t6, $t6, $t9
	j loop
		
out:	
	la $a0, str
	li $v0, 4
	syscall		
	 	
	# end
	li $v0, 10
	syscall
	
	
	

	
	
	
