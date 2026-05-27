#include "resistor_color_duo.h"
#include <stdlib.h>

int color_code(resistor_band_t *bands) {
    char output[3] = {*bands + '0', *(bands + 1) + '0', '\0'};
    return atoi(output);
}
