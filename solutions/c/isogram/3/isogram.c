#include "isogram.h"
#include <ctype.h>
#include <string.h>

bool is_isogram(const char phrase[]) {
    if (phrase == NULL) {
        return false;
    }

    char cpy_phrase[strlen(phrase)];

    // remove spaces and hythens and make a copy of the const input
    char *i = cpy_phrase;
    while (*phrase) {
        if (*phrase == ' ' || *phrase == '-') {
            phrase++;
            continue;
        }
        *i = *phrase;
        i++;
        phrase++;
    }
    *i = '\0';

    // lower case
    for (unsigned int i = 0; i < strlen(cpy_phrase); i++) {
        cpy_phrase[i] = tolower(cpy_phrase[i]);
    }

    char *cursor = cpy_phrase; // ptr to start
    while (*cursor) {
        cursor++;
        char *i = cpy_phrase; // ptr to start
        while (i < cursor) {
            if (*i == *cursor) return false;
            i++;
        }
    }
    return true;
}
