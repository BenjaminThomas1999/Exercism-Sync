#include "sum_of_multiples.h"
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define BUFFERSIZE 512

void remove_duplicates(
    unsigned int *set,
    unsigned int *set_len) { // could improve by sorting first

    unsigned int initial_set_len = *set_len;

    for (unsigned int read = 0, write = 0; read < initial_set_len; read++) {
        bool duplicate = false;

        for (unsigned int cursor = 0; cursor < read; cursor++) {
            if (set[cursor] == set[read]) {
                duplicate = true;
                break;
            }
        }

        if (!duplicate) {
            set[write++] = set[read];
        } else {
            (*set_len)--;
        }
    }
}

unsigned int sum(const unsigned int *factors, const size_t number_of_factors,
                 const unsigned int limit) {
    unsigned int *total_set =
        malloc(sizeof(unsigned int) * number_of_factors * limit);
    unsigned int total_set_len = 0;

    for (unsigned int i = 0; i < number_of_factors; i++) {
        if (factors[i] == 0) continue;

        unsigned int *set =
            malloc(sizeof(unsigned int) * limit); // deliberately oversized
        unsigned int set_len = 0;

        for (unsigned int j = 1; factors[i] * j < limit; j++) {
            set[set_len++] = factors[i] * j;
        }

        memcpy(total_set + total_set_len, set, set_len * sizeof(unsigned int));

        total_set_len += set_len;

        free(set);
    }

    remove_duplicates(total_set, &total_set_len);

    unsigned int sum = 0;
    for (unsigned int i = 0; i < total_set_len; i++) {
        sum += total_set[i];
    }
    free(total_set);
    return sum;
}
