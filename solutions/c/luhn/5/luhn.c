#include "luhn.h"
#include <string.h>

void strip(char *input, char c) {
    char *output = input;
    while (*input) {
        if (*input != c) {
            *output = *input;
            output++;
        }
        input++;
    }
    *output = '\0';
}

bool luhn(const char *num) {
    int len = strlen(num);
    char buf[len + 1];
    strcpy(buf, num);
    strip(buf, ' ');

    len = strlen(buf);

    // strings of length 1 or less are not valid.
    if (len <= 1) {
        return false;
    }

    // strings must only contain number chars.
    for (int i = 0; i < len; i++) {
        int number = *(buf + i) - '0';
        if (number < 0 || number > 9) {
            return false;
        }
    }

    int index = len - 2;
    while (index >= 0) {
        int number = *(buf + index) - '0';

        number = number * 2;

        if (number > 9)
            number -= 9;

        *(buf + index) = '0' + number;
        index -= 2;
    }

    int checksum = 0;
    index = 0;
    while (index < len) {
        checksum += *(buf + index) - '0';
        index++;
    }

    if (checksum % 10)
        return false;
    else
        return true;
}
