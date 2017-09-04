

.data 
  output: .asciiz "The sum is "
.text
.globl main

main:
    #Upper 16 bits
    lui $t0, 0x0523

    #Lower 16 bits
    addi $t0, $t0, 0x01234

    lui $t1, 0x0111
    addi $t1, $t1, 0x01043
    
    add $t2, $t1, $t0

    li $v0, 4        
    la $a0, output  
    syscall

    addi $v0, $0, 1   
    add $a0, $t2, $0   
    syscall 

    add   $v0, $0, 10
    syscall 
    