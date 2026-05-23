#include "binary.h"
#include <math.h>
#include <string.h>

int convert(const char *input) {
    int sum = 0;
    int max_index = strlen(input) - 1;
    for (int i = 0; i <= max_index; i++) {
        switch (input[max_index - i]) {
        case '0':
            continue;
        case '1':
            sum += pow(2, i);
            continue;
        default:
            return -1;
        }
    }
    return sum;
}
