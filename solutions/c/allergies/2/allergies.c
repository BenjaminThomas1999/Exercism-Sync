#include "allergies.h"

bool is_allergic_to(allergen_t allergen, int input) {
    int allergen_mask = 1 << allergen;
    return allergen_mask & input;
}

allergen_list_t get_allergens(int input) {
    allergen_list_t output = {0};

    for (int i = 0; input && i < 8; input >>= 1, i++) {
        bool allergic = input & 1;
        output.allergens[i] = allergic;
        if (allergic) output.count++;
    }
    return output;
}
