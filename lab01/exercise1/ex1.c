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
    if(dna_seq == NULL) {
        return;
    }

    int cnt_A = num_occurrences(dna_seq->sequence, 'A');
    int cnt_C = num_occurrences(dna_seq->sequence, 'C');
    int cnt_G = num_occurrences(dna_seq->sequence, 'G');
    int cnt_T = num_occurrences(dna_seq->sequence, 'T');

    // for (int i = 0; i < strlen(dna_seq->sequence); i ++ ) {
    //     char cur_letter = dna_seq->sequence[i];
    //     if (cur_letter == 'A') {
    //         cnt_A ++ ;
    //     } else if (cur_letter == 'C') {
    //         cnt_C ++ ;
    //     } else if (cur_letter == 'G') {
    //         cnt_G ++ ;
    //     } else if (cur_letter == 'T') {
    //         cnt_T ++ ;
    //     }
    // }

    dna_seq -> A_count = cnt_A;
    dna_seq -> C_count = cnt_C;
    dna_seq -> G_count = cnt_G;
    dna_seq -> T_count = cnt_T;

    return;
}
