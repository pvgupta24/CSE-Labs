.data
a: .space 10000
b: .space 10000

.text


.globl main

main:



#Exit
    add   $v0, $0, 10
    syscall 