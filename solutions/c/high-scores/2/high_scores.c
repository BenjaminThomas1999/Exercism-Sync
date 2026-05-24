#include "high_scores.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int32_t latest(const int32_t *scores, size_t scores_len) {
    return scores[scores_len - 1];
}

int32_t personal_best(const int32_t *scores, size_t scores_len) {
    int32_t highest = scores[0];
    for (size_t i = 1; i < scores_len; i++) {
        if (scores[i] > highest) {
            highest = scores[i];
        }
    }
    return highest;
}

static int comp(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);
}

size_t personal_top_three(const int32_t *scores, size_t scores_len,
                          int32_t *output) {
    // make a copy to not modify input in place
    int32_t scores_cpy[scores_len];
    memcpy(scores_cpy, scores, scores_len * sizeof(scores[0]));

    qsort(scores_cpy, scores_len, sizeof(scores[0]), comp);

    for (unsigned int i = 0; i < 3 && i < scores_len; i++) {
        output[i] = scores_cpy[i];
    }

    if (scores_len < 3) {
        return scores_len;
    }
    return 3;
}
