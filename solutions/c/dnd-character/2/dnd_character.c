#include "dnd_character.h"
#include <math.h>
#include <stdlib.h>

int ability(void) {
    int sum = 0;
    int lowest = 6;
    for (int i = 0; i < 4; i++) {
        int r = rand() % 6 + 1;
        if (r < lowest) lowest = r;
        sum += r;
    }
    sum -= lowest;
    return sum;
}
int modifier(int score) { return floor((score - 10.0) / 2.0); }

dnd_character_t make_dnd_character(void) {
    dnd_character_t c = {.strength = ability(),
                         .dexterity = ability(),
                         .constitution = ability(),
                         .intelligence = ability(),
                         .wisdom = ability(),
                         .charisma = ability()};

    c.hitpoints = 10 + modifier(c.constitution);
    return c;
}
