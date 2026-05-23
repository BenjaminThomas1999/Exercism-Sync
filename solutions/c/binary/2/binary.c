#include "binary.h"
#include <string.h>

int convert(const char *input) {
    int sum = 0;
    int max_index = strlen(input) - 1;
    for (int i = 0; i <= max_index; i++) {
        sum = sum << 1;
        switch (input[max_index - i]) {
        case '0':
            break;
        case '1':
            sum |= 1;
            break;
        default:
            return -1;
        }
    }
    return sum;
}
