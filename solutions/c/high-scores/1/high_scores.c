#include "high_scores.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int32_t latest(const int32_t *scores, size_t scores_len) {
    return scores[scores_len - 1];
}

int32_t personal_best(const int32_t *scores, size_t scores_len) {
    int32_t highest = 0;
    for (size_t i = 0; i < scores_len; i++) {
        if (scores[i] > highest) {
            highest = scores[i];
        }
    }
    return highest;
}

void swap(int32_t *arr, size_t i_1, size_t i_2) {
    int32_t tmp = arr[i_1];
    arr[i_1] = arr[i_2];
    arr[i_2] = tmp;
}

void reverse_sort_array_of_three(int32_t *arr) {
    if (arr[0] < arr[1]) {
        swap(arr, 0, 1);
    }

    if (arr[1] < arr[2]) {
        swap(arr, 1, 2);
    }

    if (arr[0] < arr[1]) {
        swap(arr, 0, 1);
    }
}

int find_index_to_replace(const int32_t *output, int32_t compare) {
    if (compare > output[2]) {
        return 2;
    }
    if (compare > output[1]) {
        return 1;
    }
    if (compare > output[0]) {
        return 0;
    }
    return -1;
}

size_t personal_top_three(const int32_t *scores, size_t scores_len,
                          int32_t *output) {
    output[0] = 0;
    output[1] = 0;
    output[2] = 0;

    for (size_t i = 0; i < scores_len; i++) {
        reverse_sort_array_of_three(output);
        int i_replace = find_index_to_replace(output, scores[i]);
        if (i_replace != -1) {
            output[i_replace] = scores[i];
        }
    }

    reverse_sort_array_of_three(output);

    int zero_count = 0;

    for (int i = 0; i < 3; i++) {
        if (output[i] == 0) zero_count++;
    }

    return 3 - zero_count;
}
