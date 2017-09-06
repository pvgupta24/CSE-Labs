# Author	: Praveen Gupta (16C0235)
# Date		: 4th Sept 2017    
    #Initialize array of 10 two digit numbers


    .data
    #Array of 10 , 2-digit numbers
    array: .word 11 12 13 14 15 16 17 18 19 25  

    .text
    .globl main

    main:
        #Using t0 as counter
        add $t0, $0, $0
        #Storing 10 in t1
        addi $t1, $0, 10
        #Storing sum in t2
        add $t2, $0, $0

        #Address of first element of array int3
        la $t3, array
    
        loop:          
            #End loop if counter reaches 10
            beq $t0 , $t1 , endLoop 
            #Store current word in t4
            lw $t4, 0($t3)
            #Adding it to sum
            add $t2,$t2,$t4
            #Incrementing counter
            addi $t0, $t0, 1
            #Moving to next element
            addi $t3, $t3, 4    
            #looping it back
            j loop
            
        endLoop:
            #Printing the sum of array
            addi $v0, $0, 1   
            add $a0, $t2, $0   
            syscall 

            #Exit
            add   $v0, $0, 10
            syscall 