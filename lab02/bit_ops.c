#include <stdio.h>
#include "bit_ops.h"

/* Returns the Nth bit of X. Assumes 0 <= N <= 31. */
unsigned get_bit(unsigned x, unsigned n) {
    /* YOUR CODE HERE */
    return (x >> n) & 1; /* UPDATE WITH THE CORRECT RETURN VALUE*/
}

/* Set the nth bit of the value of x to v. Assumes 0 <= N <= 31, and V is 0 or 1 */
void set_bit(unsigned *x, unsigned n, unsigned v) {
    /* YOUR CODE HERE */
    unsigned mask = -1;
    mask = mask << (n + 1);
    // printf("mask: %032b\n", mask);

    unsigned flip_mask = ~mask >> 1;
    // printf("flip: %032b\n", flip_mask);
    
    mask = mask ^ flip_mask;
    // printf("mask: %032b\n", mask);

    // printf("*x  : %032b, v = %d\n", *x, v);
    unsigned other = *x & mask;
    // printf("othe: %032b\n", other);

    unsigned bit = get_bit(*x, n);
    unsigned is_one = 1 & bit;
    unsigned flip = (v ^ bit ^ is_one) << n;
    // printf("flip: %032b\n", flip);
    *x = other | flip;
}

/* Flips the Nth bit in X. Assumes 0 <= N <= 31.*/
void flip_bit(unsigned *x, unsigned n) {
    /* YOUR CODE HERE */
    unsigned mask = -1;
    mask = mask << (n + 1);
    unsigned flip_mask = ~mask >> 1;
    mask = mask ^ flip_mask;
    unsigned other = *x & mask;
    // printf("othe: %032b\n", other);

    unsigned bit = get_bit(*x, n);
    unsigned is_zero = !(0 | bit);
    unsigned is_one = 1 & bit;
    unsigned flip = ((bit | is_zero) ^ is_one) << n;
    // printf("flip: %032b\n", flip);
    // printf("zero: %d, bit: %d\n", is_zero, bit);
    // printf("flip: %032b\n", flip);
    // printf("*x  : %032b\n", *x);
    *x = other | flip;
    // printf("*x  : %032b\n", *x);
}

