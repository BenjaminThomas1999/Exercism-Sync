#include "sieve.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

uint32_t sieve(uint32_t limit, uint32_t *primes, size_t max_primes) {
    bool marked[limit - 1];
    uint32_t all_numbers[limit - 1];
    uint32_t prime_count = 0;

    for (uint32_t i = 0; i < limit - 1; i++) {
        marked[i] = false;
        all_numbers[i] = i + 2;
    }

    for (uint32_t i = 0; i < limit - 1; i++) {
        if (!marked[i]) {
            if (prime_count < max_primes) primes[prime_count++] = all_numbers[i];
            uint32_t multiplier = 2;
            while (all_numbers[i] * multiplier <= limit) {
                marked[all_numbers[i] * multiplier - 2] = true;
                multiplier++;
            }
        }
    }

    return prime_count;
}
