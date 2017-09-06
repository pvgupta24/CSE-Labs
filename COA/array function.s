# Author	: Praveen Gupta (16C0235)
# Date		: 4th Sept 2017


#Implement a function that calculates the sum of the elements of the array. The function accepts the length of
#the array and the address of the first element of the array. The function returns the sum to the caller. The
#main procedure calculates the average of the elements of the array. The main procedure uses the mentioned
#the function. Use the MIPS compiler subroutine conventions for this code.

.data
    first: .asciiz "Sum = "
    second: .asciiz "\nAverage = "
    array : .word 1 2 4 6 
    length : .word 4
    
.globl main

.text

    main:

        la $a0, array
        lw $a1, length

        jal findSum

        li $v0, 4        
        la $a0, first  
        syscall

        #Printing the sum of array
        addi $v0, $0, 1   
        add $a0, $v1, $0   
        syscall 

        li $v0, 4        
        la $a0, second  
        syscall
        
        #Printing the average of array
        addi $v0, $0, 1   
        lw $a1, length

        li.s $f1, 2.0
        li.s $f2, 9.0
        li $v0, 2
        div $v1, $a1  
        #mflo $a0
        syscall 


        #Exit
        add   $v0, $0, 10
        syscall 

    findSum:
    
        loop:          
            #End loop if counter reaches 10
            beq $a1 , $0 , endLoop 
            #Store current word in t4
            lw $t4, 0($a0)
            #Adding it to sum
            add $v1, $v1, $t4
            #n--
            addi $a1, $a1, -1
            #Moving to next element
            addi $a0, $a0, 4    
            #looping it back
            j loop

        endLoop:
    jr $ra