#include "rotational_cipher.h"
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

enum char_type { UPPER, LOWER, OTHER };

char *rotate(const char *text, int shift_key) {
    char *output = malloc(strlen(text) + 1);
    char *output_0 = output;

    shift_key = shift_key % 26;

    for (const char *cursor = text; *cursor; cursor++, output++) {
        enum char_type type;

        if (*cursor <= 'z' && *cursor >= 'a') type = LOWER;
        else if (*cursor <= 'Z' && *cursor >= 'A') type = UPPER;
        else type = OTHER;

        if (type == LOWER || type == UPPER) {
            int tmp = *cursor + shift_key;

            if (tmp > 'z' && type == LOWER) tmp -= 26;
            else if (tmp > 'Z' && type == UPPER) tmp -= 26;

            *output = tmp;
        } else {
            *output = *cursor;
        }
    }
    *output = '\0';

    return output_0;
}
