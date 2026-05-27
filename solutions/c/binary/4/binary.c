#include "binary.h"
#include <string.h>

int convert(const char *input) {
    int output = 0;
    for (int i = 0; i <= (int)strlen(input) - 1; i++) {
        output = output << 1;
        switch (input[i]) {
        case '0':
            break;
        case '1':
            output |= 1;
            break;
        default:
            return -1;
        }
    }
    return output;
}
