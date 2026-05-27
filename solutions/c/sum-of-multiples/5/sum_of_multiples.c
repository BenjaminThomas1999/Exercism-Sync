#include "sum_of_multiples.h"

unsigned int sum(const unsigned int *factors, const size_t number_of_factors,
                 const unsigned int limit) {
    unsigned int total = 0;
    for (unsigned int multiple = 1; multiple < limit; multiple++) {
        for (unsigned int i = 0; i < number_of_factors; i++) {
            if (!factors[i]) continue;
            if (multiple % factors[i] == 0) {
                total += multiple;
                break;
            }
        }
    }
    return total;
}
