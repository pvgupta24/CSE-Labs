#Hello World

.data   
    output: .asciiz "Hello World !!!\n"

.text
.globl main

main:
    li $v0, 4        
    la $a0, output  
    syscall 

    add   $v0, $0, 10
    syscall 