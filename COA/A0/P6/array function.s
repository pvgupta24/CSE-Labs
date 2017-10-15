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
        addi $v0, $0, 3   

        #v1 has sum a1 has length, Storev1/a1 in a0
        lw $a1, length

        mtc1.d $a1, $f10
        cvt.d.w $f10, $f10

        mtc1.d $v1, $f8
        cvt.d.w $f8, $f8
        
        div.d $f12, $f8, $f10 
       # mov.d 
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