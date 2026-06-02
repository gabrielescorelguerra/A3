#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "constants.h"

typedef struct Mob {
    int x;
    int y;
    int w;
    int h;

    int max_x;
    int min_x;

    int step_size;
    int trajectory;
} Mob;

Mob *mob_create(int x, int y, int w, int h, int range_x, int range_y, float step_size);
void mob_move(Mob *mob);

#endif