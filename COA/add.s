# Author	: Praveen Gupta (16C0235)
# Date		: 4th Sept 2017

.data 
  output: .asciiz "The sum is "
.text
.globl main

main:
    #Upper 16 bits
    lui $t0, 0x0523
    #Lower 16 bits
    addi $t0, $t0, 0x01234

    #Upper 16 bits
    lui $t1, 0x0111
    #Lower 16 bits    
    addi $t1, $t1, 0x01043
    
    add $t2, $t1, $t0

    #Print "The sum is "
    li $v0, 4        
    la $a0, output  
    syscall

    #Print sum
    addi $v0, $0, 1   
    add $a0, $t2, $0   
    syscall 

    #Exit
    add   $v0, $0, 10
    syscall 
    