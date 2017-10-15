# Author	: Praveen Gupta (16C0235)
# Date		: 5th Sept 2017

#Factorial Program using recursion

.data
    inp: .asciiz "Enter n: "
    out: .asciiz "Factorial of n is: "
    err: .asciiz "Enter +ve number\n"
 
.globl main
.text
main:
    # ask user for input
    la        $a0, inp
    li        $v0, 4
    syscall
 
    li        $v0, 5    
    syscall
    move      $t0, $v0

    #if negative -> error Print error and restart
    blt $t0, $0, error

    # Call fact function

    #Prelogue  


    ####### Stack #######
    #     Current ra    #
    #   Store product   #
    #     Current n     #
    #####################

    # Move down by 12 bytes i.e make space for 3 words
    addi      $sp, $sp, -12  
    # n at bottom
    sw        $t0, 0($sp)    
    # save original ra
    sw        $ra, 8($sp)    

    jal       fact

    #Epilogue
    # restore ra
    lw        $ra, 8($sp)    
    # load the final return value
    lw        $s0, 4($sp)    
    # POP 12 bytes
    addi      $sp, $sp, 12   
 
    # Print result msg
    la        $a0, out
    li        $v0, 4
    syscall
 
    # Print result 
    move      $a0, $s0
    li        $v0, 1
    syscall
    
    #EXIT
    exit:
        li        $v0, 10
        syscall
 
        fact:

            # base case
            lw        $t0, 0($sp)
            beq       $t0, 0, ret1
            
            #n--
            addi      $t0, $t0, -1
            # call fact recursively

            #Prelogue    
            addi      $sp, $sp, -12
            sw        $t0, 0($sp)
            sw        $ra, 8($sp)

            jal       fact

            #Epilogue
            lw        $ra, 8($sp)
            lw        $t1, 4($sp)

            #Retrieve n from last element of previous frame
            lw        $t0, 12($sp)
            mul       $t2, $t1, $t0
            # save the product to previous function's return value
            sw        $t2, 16($sp)
            addiu     $sp, $sp, 12
        
            jr        $ra

            #If n==1 
            ret1:
                li        $t0, 1
                sw        $t0, 4($sp)
                jr        $ra


 error:
        li $v0, 4        
        la $a0, err  
        syscall
        j main




