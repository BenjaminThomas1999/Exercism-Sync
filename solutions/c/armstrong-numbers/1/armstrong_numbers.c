#include "armstrong_numbers.h"
#include <math.h>
#include <stdio.h>
#include <string.h>

bool is_armstrong_number(int candidate) {
    char num_s[16];
    sprintf(num_s, "%d", candidate);
    int len = strlen(num_s);
    int sum = 0;
    for (int i = 0; i < len; i++) {
        sum += pow((num_s[i] - '0'), len);
    }
    if (sum == candidate) {
        return true;
    }
    return false;
}
