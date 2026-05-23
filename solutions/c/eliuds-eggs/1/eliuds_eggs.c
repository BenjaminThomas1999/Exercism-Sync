#include "eliuds_eggs.h"

int egg_count(int display) {
    int count = 0;
    for (int i = 0; i < (int)sizeof(int) * 8; i++) {
        if (display & 1) count++;
        display = display >> 1;
    }
    return count;
}
