#ifndef LUHN_H
#define LUHN_H

#include <stdbool.h>

bool luhn(const char *num);

void strip(char *input, char c);

#endif
