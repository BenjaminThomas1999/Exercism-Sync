#include "pangram.h"
#include <ctype.h>
#include <stdint.h>

bool is_pangram(const char *sentence) {
    if (!sentence) {
        return false;
    }

    int32_t letter_mask = 0;
    int32_t pangram_mask = (1 << 26) - 1;

    for (const char *i = sentence; *i; i++) {
        unsigned int letter_shift = tolower(*i) - 'a';
        if (letter_shift > 26) continue;
        letter_mask |= 1 << letter_shift;
        if (letter_mask == pangram_mask) return true;
    }

    return false;
}
