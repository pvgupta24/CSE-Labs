# Author	: Praveen Gupta (16C0235)
# Date		: 4th Sept 2017

#Load a 32b constant in the memory location pointed to by the global pointer. Load another 32b constant in
#the first memory location of the data segment. Add them both and save the sum in the 100 th word of the data
#segment.

.data 
    output: .asciiz "Global Pointer \n"
    n: .word 0
.text
.globl main

main:
    
    #Upper 16 bits
    lui $t0, 0x0523
    #Lower 16 bits
    addi $t0, $t0, 0x01234
    sw $t0, 0($gp)

    #Address of first data segment memory location
    la $t4, 0x10000000

    #32b constant in first data segment memory location
    lui $t1, 0x0111
    addi $t1, $t1, 0x01043
    sw $t1, 0($t4)

    #Sum in 100th word location
    add $t3, $t1, $t0
    sw $t3, 400($t4)

    #li $v0, 4        
    #la $a0, output  
    #syscall

    #Print to console
    #addi $v0, $0, 1   
    #add $a0, $t3, $0   
    #syscall 

    #Exit
    add   $v0, $0, 10
    syscall 