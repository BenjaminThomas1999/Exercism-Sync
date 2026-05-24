#include "pangram.h"
#include <ctype.h>
#include <stdint.h>
#include <string.h>

bool is_pangram(const char *sentence) {
    if (sentence == NULL || strlen(sentence) < 1) {
        return false;
    }
    int32_t letter_mask = 0;
    for (const char *i = sentence; *i; i++) {
        unsigned int letter_shift = tolower(*i) - 'a';
        if (letter_shift > 26) {
            continue;
        }
        int32_t i_letter_mask = 1 << letter_shift;
        letter_mask |= i_letter_mask;
    }

    int32_t full_letter_mask = 1;
    for (int i = 1; i < 26; i++) {
        full_letter_mask <<= 1;
        full_letter_mask += 1;
    }

    if (letter_mask == full_letter_mask) return true;
    else return false;
}
