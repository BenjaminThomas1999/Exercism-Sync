#include "resistor_color_trio.h"
#include <math.h>

resistor_value_t color_code(resistor_band_t bands[3]) {
    resistor_value_t resistor;
    resistor.band_1 = bands[0];
    resistor.band_2 = bands[1];
    resistor.band_3 = bands[2];

    resistor.value =
        (resistor.band_1 * 10 + resistor.band_2) * pow(10, resistor.band_3);

    resistor.unit = OHMS;
    while (resistor.value > 999) {
        resistor.value = resistor.value / 1000;
        resistor.unit++;
    }
    return resistor;
}
