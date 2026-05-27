#include "rna_transcription.h"
#include <stdlib.h>
#include <string.h>

char *to_rna(const char *dna) {
    char *rna_0 = malloc(sizeof(char) * (strlen(dna) + 1));
    char *rna = rna_0;
    while (*dna) {
        switch (*dna) {
        case 'G':
            *rna = 'C';
            break;
        case 'C':
            *rna = 'G';
            break;
        case 'T':
            *rna = 'A';
            break;
        case 'A':
            *rna = 'U';
            break;
        default:
            free(rna_0);
            return NULL;
        }
        rna++;
        dna++;
    }
    *rna = '\0';
    return rna_0;
}
