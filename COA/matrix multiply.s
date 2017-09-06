# Author	: Praveen Gupta (16C0235)
# Date		: 5th Sept 2017

.data
    m1: .word 1 2 3 4
    m2: .word 5 6 7 8
    #r1 c1 r2 c2
    sizes: .word 2 2 2 2 
    ans: .word 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

    error: .asciiz "c1 should be equal to r2\n"

.text

.globl main
main:

la $t0, sizes

#r1 c1 r2 c2

lw $s0, 0($t0)
lw $s1, 4($t0)
lw $s2, 8($t0)
lw $s3, 12($t0)

beq $s1, $s2, return
    la $a0, error
	li $v0, 4
	syscall
    j exit

return:
#Starting address of matrices
la $t4, m1
la $t5, m2


#t0 ,t1, t2, t3 count till r1, c1, r2, c2
li $t3, 0
li $t2, 0
li $t1, 0
li $t0, 0

outer:
beq $t0, $s0, breakOuter
    middle:
    beq $t3, $s3, breakMiddle
        #sum in t6
        li $t6, 0
        inner: 
        beq $t2, $s2, breakInner

            #for ( i = 0; i < r1; i++) {
            #   for ( j = 0; j <c2; j++) {
            #      int sum = 0;
            #           for (k = 0; k < r2; k++)
            #               sum = sum + a[i * c1 + k] * b[k * c2 + j];
            #           ans[i * c2 + j] = sum;
            #      }   }

            li $a0, 0
            li $t9, 1
            sll $t9, $t0, 2
            mul $t9, $t9, $s1
            add $a0, $t4, $t9

            li $t9, 1            
            sll $t9, $t2, 2
            add $a0, $a0, $t9

            lw $a0, 0($a0)

            li $a1, 0
            li $t9, 1            
            sll $t9, $t2, 2
            mul $t9, $t9, $s3
            add $a1, $t5, $t9

            li $t9, 1            
            sll $t9, $t3, 2
            add $a1, $a1, $t9
            lw $a1, 0($a1)

            mul $t8, $a0, $a1
            add $t6, $t6, $t8

           # move $a0, $t6
           # addi $v0, $0, 1     
           #syscall

            addi $t2, $t2, 1
            j inner

        breakInner:
        #Assume ans matrix starts from 0th
        la $t8, 0x10000000  
        #move $s7, $gp
        li $t9, 1
        sll $t9, $t0, 2
        mul $t9, $t9, $s3

        sll $t7, $t3, 2

        add $t7, $t7, $t9
        add $t8, $t8, $t7

        sw $t6, 0($t8)
        #j exit

        addi $t3, $t3, 1
        j middle

    breakMiddle:
    addi $t0, $t0, 1
    j outer

breakOuter: 


#Exit
exit:
    add   $v0, $0, 10
    syscall 