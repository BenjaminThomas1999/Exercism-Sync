#include "queen_attack.h"
// typedef enum { CAN_NOT_ATTACK, CAN_ATTACK, INVALID_POSITION }
// attack_status_t;

int valid_position(position_t pos) {
    if (pos.row > 7) {
        return 0;
    }
    if (pos.column > 7) {
        return 0;
    }
    return 1;
}

attack_status_t can_attack(position_t queen_1, position_t queen_2) {
    if (!valid_position(queen_1) || !valid_position(queen_2)) {
        return INVALID_POSITION;
    }
    if (queen_1.column == queen_2.column) {
        if (queen_1.row == queen_2.row) {
            return INVALID_POSITION;
        }
    }

    if (queen_1.row == queen_2.row) {
        return CAN_ATTACK;
    }
    if (queen_1.column == queen_2.column) {
        return CAN_ATTACK;
    }

    if (queen_1.row - queen_2.row == queen_1.column - queen_2.column) {
        return CAN_ATTACK;
    }

    if (queen_2.row - queen_1.row == -(queen_2.column - queen_1.column)) {
        return CAN_ATTACK;
    }

    return CAN_NOT_ATTACK;
}
