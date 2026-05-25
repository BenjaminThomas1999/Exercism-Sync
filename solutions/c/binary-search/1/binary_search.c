#include "binary_search.h"
#include <stdbool.h>

const int *binary_search(int value, const int *arr, size_t length) {
    if (length == 1) {
        if (*arr == value) return arr;
        else return NULL;
    }

    if (length < 1) return NULL;

    size_t middle = length / 2;

    if (*(arr + middle) == value) return arr + middle;

    if (*(arr + middle) > value) {
        return binary_search(value, arr, middle);
    }
    if (*(arr + middle) < value)
        return binary_search(value, arr + middle + 1, length - middle - 1);

    return NULL;
}
