#include "collatz_conjecture.h"

int steps(int input) {
    if (input < 1) {
        return -1;
    }
    int steps = 0;
    while (input > 1) {
        if (input % 2) { // odd
            input = input * 3 + 1;
        } else { // even
            input = input / 2;
        }
        steps++;
    }
    return steps;
}
