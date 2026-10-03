#include "rotational_cipher.h"
#include <stdlib.h>
#include <string.h>

char *rotate(const char *text, int shift_key) {
    char *output = malloc(strlen(text) + 1);
    char *output_0 = output;

    shift_key = shift_key % 26;

    for (const char *cursor = text; *cursor; cursor++, output++) {
        int tmp = *cursor + shift_key;
        if (*cursor <= 'z' && *cursor >= 'a') {
            if (tmp > 'z') tmp -= 26;
            *output = tmp;
        } else if (*cursor <= 'Z' && *cursor >= 'A') {
            if (tmp > 'Z') tmp -= 26;
            *output = tmp;
        } else {
            *output = *cursor;
        }
    }
    *output = '\0';

    return output_0;
}
