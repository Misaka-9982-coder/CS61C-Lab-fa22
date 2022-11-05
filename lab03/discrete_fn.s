.globl f # this allows other files to find the function f

# f takes in two arguments:
# a0 is the value we want to evaluate f at
# a1 is the address of the "output" array (defined above).
# The return value should be stored in a0
f:
    slli a2, a0, 2 # step 1 multiply the index by the size of the elements of the array.
    add a2, a2, a1 # step 2 add this offset to the address of the array to get the address of the element
    lw a0, 12(a2)  # step 3 add the offset and read the element
    # This is how you return from a function. You'll learn more about this later.
    # This should be the last line in your program.
    jr ra  