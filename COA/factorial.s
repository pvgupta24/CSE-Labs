#Factorial Program. Load a random number in $t0. Calculate its factorial using (a) loops
.data
    n: .word 5
    err: .asciiz "Enter +ve number\n"
.globl main

.text

main:
    lw $t0,n
    addi $a0, $0, 1

    blt $t0, $0, error
    loop:
        beq $t0, $0, endLoop
        mul $a0, $a0, $t0
        addi $t0, $t0, -1
        j loop

    endLoop:

    addi $v0, $0, 1     
    syscall 


    #Exit
    add   $v0, $0, 10
    syscall 

    error:
        li $v0, 4        
        la $a0, err  
        syscall
        
        #Exit
        add   $v0, $0, 10
        syscall 