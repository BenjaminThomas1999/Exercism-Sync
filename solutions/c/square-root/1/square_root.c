#include "square_root.h"

int square_root(int n) {
    for (int i = 0; i <= n; i++) {
        if (i * i == n) {
            return i;
        }
    }
    return -1;
}
