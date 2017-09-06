# Author	: Praveen Gupta (16C0235)
# Date		: 4th Sept 2017


.data
	str:	.asciiz		"HelloWorld..."
	len:	.word		13
	
.text

.globl main
		
main: 	
	
	#Load String
	la $t0, str
	la $t1, len
	lw $t1, 0($t1)

	#Divide length by 2
	li $t2, 2
	div $t1, $t2	
	
	mflo $t2

	li $t6, 0
	li $t9, 1
	add $t6, $t0, $t1
	sub $t6 $t6, $t9
	 
	#t3 is counter
	li $t3, 0
	
	loop:

		#Loop till half the length and swap corresponding elements
		beq $t2, $t3 out
		lb $t4, 0($t0)
		lb $t5, 0($t6)
		sb $t5, 0($t0)
		sb $t4, 0($t6)

		addi $t3, $t3, 1
		addi $t0, $t0, 1
		sub $t6, $t6, $t9
		j loop
		
	#Print reverse string
	out:	
		la $a0, str
		li $v0, 4
		syscall		
	 	
	# EXIT
	li $v0, 10
	syscall
	
	
	

	
	
	
