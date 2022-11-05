.globl factorial

.data
n: .word 8

.text
# Don't worry about understanding the code in main
# You'll learn more about function calls in lecture soon
main:
    la t0, n
    lw a0, 0(t0)
    jal ra, factorial

    addi a1, a0, 0
    addi a0, x0, 1
    ecall # Print Result

    addi a1, x0, '\n'
    addi a0, x0, 11
    ecall # Print newline

    addi a0, x0, 10
    ecall # Exit

# factorial takes one argument:
# a0 contains the number which we want to compute the factorial of
# The return value should be stored in a0
factorial:
    # YOUR CODE HERE
    # a0 = n
    addi t0, x0, 1 # res = 1
    addi t3, x0, 1 # flag = 1
loop_outer:
    beq a0, x0, finish_outer # n > 0
    addi a1, a0, -1 # i = n - 1
    add t1, x0, x0 # tmp = 0
loop_inner:
    beq a1, x0, finish_inner # i > 0
    add t1, t1, t0 # tmp = tmp + res
    addi a1, a1, -1 # i -- 
    j loop_inner
finish_inner:
    add t0, t0, t1 # res = res + tmp
    addi a0, a0, -1 # n -- 
    j loop_outer
finish_outer:
    add a0, t0, x0 # return res
    # This is how you return from a function. You'll learn more about this later.
    # This should be the last line in your program.
    jr ra
