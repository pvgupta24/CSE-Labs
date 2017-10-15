# Author	: Praveen Gupta (16C0235)
# Date		: 5th Sept 2017

#Factorial Program. Load a random number in $t0. Calculate its factorial using loops
.data
    n: .word 5
    err: .asciiz "Enter +ve number\n"
    inp: .asciiz "Enter n: "
    out: .asciiz "Factorial of n is: "
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

    #load 1 in product variable
    addi $t1, $0, 1

    #if negative -> error
    blt $t0, $0, error

    loop:
        beq $t0, $0, endLoop
        mul $t1, $t1, $t0
        addi $t0, $t0, -1
        j loop

    endLoop:

    # Print result msg
    la        $a0, out
    li        $v0, 4
    syscall

    #Print factorial
    move $a0, $t1
    addi $v0, $0, 1     
    syscall 


    #Exit   
    exit:
        add   $v0, $0, 10
        syscall 

    error:
        li $v0, 4        
        la $a0, err  
        syscall
        j main
        