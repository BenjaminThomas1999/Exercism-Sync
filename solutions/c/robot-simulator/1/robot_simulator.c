#include "robot_simulator.h"

robot_status_t robot_create(robot_direction_t direction, int x, int y) {
    robot_status_t new;
    new.direction = direction;
    new.position.x = x;
    new.position.y = y;

    return new;
}

static void rotate(robot_status_t *robot, int turns) {
    for (; turns > 0; turns--) {
        robot->direction++;
        if (robot->direction == DIRECTION_MAX) {
            robot->direction = DIRECTION_NORTH;
        }
    }
}

static void advance(robot_status_t *robot) {
    switch (robot->direction) {
    case DIRECTION_NORTH:
        robot->position.y++;
        break;
    case DIRECTION_EAST:
        robot->position.x++;
        break;
    case DIRECTION_SOUTH:
        robot->position.y--;
        break;
    case DIRECTION_WEST:
        robot->position.x--;
        break;
    case DIRECTION_MAX:
        return;
    }
}

void robot_move(robot_status_t *robot, const char *commands) {
    for (const char *c = commands; *c; c++) {
        switch (*c) {
        case 'L':
            rotate(robot, 3);
            break;
        case 'R':
            rotate(robot, 1);
            break;
        case 'A':
            advance(robot);
            break;
        default:
            return;
        }
    }
}
