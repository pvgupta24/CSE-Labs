# Author	: Praveen Gupta (16C0235)
# Date		: 4th Sept 2017

# Hello World

.data   
    output: .asciiz "Hello World ...\n"

.text
.globl main

main:
    #Print output
    li $v0, 4        
    la $a0, output  
    syscall 

    #Exit
    add   $v0, $0, 10
    syscall 