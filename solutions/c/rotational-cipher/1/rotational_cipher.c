#include "rotational_cipher.h"
#include <stdlib.h>
#include <string.h>

char *rotate(const char *text, int shift_key) {
    // create a contigious stretch of memory the same length as text and point output at the start of it.
    char *output = malloc(strlen(text) + 1);
    char *output_0 = output;
    // normalise shift key
    shift_key = shift_key % 26;

    // create a pointer to the start of text, const means I won't modify text
    const char *cursor = text;
    while (*cursor) {

        if (*cursor <= 'z' && *cursor >= 'a') {
            int tmp = *cursor + shift_key;
            if (tmp > 'z') tmp -= 26;
            *output = tmp;
        } else if (*cursor <= 'Z' && *cursor >= 'A') {
            int tmp = *cursor + shift_key;
            if (tmp > 'Z') tmp -= 26;
            *output = tmp;
        } else {
            *output = *cursor;
        }

        output++;
        cursor++;
    }
    *output = '\0';

    return output_0;
}
