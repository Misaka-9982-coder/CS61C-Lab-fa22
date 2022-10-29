#include <string.h>
#include "ex1.h"

/* Returns the number of times LETTER appears in STR.
There are two different ways to iterate through a string.
1st way hint: strlen() may be useful
2nd way hint: all strings end in a null terminator */
int num_occurrences(char *str, char letter) {
    /* TODO: implement num_occurrences */
    if (!letter) {
        return 0;
    }

    int cnt = 0;

    // 1st way 
    // for (int i = 0; i < strlen(str); i ++ ) {
    //     if (str[i] == letter) {
    //         cnt ++ ;
    //     }
    // }

    // 2nd way
    for (int i = 0; str[i] != '\0'; i ++ ) {
        if (str[i] == letter) {
            cnt ++ ;
        }
    }

    return cnt;
}

/* Populates DNA_SEQ with the number of times each nucleotide appears.
Each sequence will end with a NULL terminator and will have up to 20 nucleotides.
All letters will be upper case. */
void compute_nucleotide_occurrences(DNA_sequence *dna_seq) {
    /* TODO: implement compute_nucleotide_occurrences */
    return;
}
