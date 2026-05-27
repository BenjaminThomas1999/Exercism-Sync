#ifndef SUM_OF_MULTIPLES_H
#define SUM_OF_MULTIPLES_H

#include <stddef.h>

void remove_duplicates(unsigned int *set, unsigned int *set_len);

unsigned int sum(const unsigned int *factors, const size_t number_of_factors,
                 const unsigned int limit);

#endif
