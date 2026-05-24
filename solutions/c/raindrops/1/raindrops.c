#include "raindrops.h"
#include <stdio.h>
#include <string.h>

void make_sound(char result[], char sound[], int mod, int drops) {
    if (!(drops % mod)) {
        strcat(result, sound);
    }
}

void convert(char result[], int drops) {
    strcpy(result, "");
    make_sound(result, "Pling", 3, drops);
    make_sound(result, "Plang", 5, drops);
    make_sound(result, "Plong", 7, drops);

    if (strlen(result) == 0) {
        sprintf(result, "%d", drops);
    }
}
