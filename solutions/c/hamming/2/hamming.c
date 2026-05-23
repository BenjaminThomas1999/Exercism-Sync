#include "hamming.h"

int compute(const char *lhs, const char *rhs) {
    int hamming = 0;
    while (*lhs && *rhs) {
        if (*lhs++ != *rhs++) hamming++;
    }
    if (*rhs != '\0' || *lhs != '\0') return -1;
    return hamming;
}
