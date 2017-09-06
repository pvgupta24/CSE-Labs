# Author	: Praveen Gupta (16C0235)
# Date		: 5th Sept 2017

#Factorial Program. Load a random number in $t0. Calculate its factorial using recursion
.data
    n: .word 5
    err: .asciiz "Enter +ve number\n"

.globl main
.text

main:



    #Exit
    add   $v0, $0, 10
    syscall 

# int fact(int n)
fact:
    subu sp, sp, 32  # Allocate a 32-byte stack frame
    sw  ra, 20(sp)  # Save Return Address
    sw  fp, 16(sp)  # Save old frame pointer
    addiu fp, sp, 28  # Setup new frame pointer
    sw  a0,  0(fp)  # Save argument (n) to stack

    lw  v0, 0(fp)   # Load n into v0
    bgtz    v0, recurse      # if n > 0 jump to rest of the function
    li  v0, 1       # n==1, return 1
    j   clearFrame      # jump to frame clean-up code

recurse:
    lw  v1, 0(fp)   # Load n into v1
    subu    v0, v1, 1   # Compute n-1
    move    a0, v0      # Move n-1 into first argument
    jal fact        # Recursive call

    lw  v1, 0(fp)   # Load n into v1
    mul v0, v0, v1  # Compute fact(n-1) * n

    #Result is in v0, so clean up the stack and return
clearFrame:
    lw  ra, 20(sp)  # Restore return address
    lw  fp, 16(sp)  # Restore frame pointer
    addiu   sp, sp, 32  # Pop stack
    jr  ra      # return