#include <stdlib.h>

#include "mob.h"

// imitar isso no player e plataform create
Mob *mob_create(int x, int y, int w, int h, int range_x, int range_y, float step_size) {
    Mob *new_mob;
    if (! (new_mob = malloc(sizeof (Mob))))
        return NULL;

    // fazer ele spawnar num x aleatorio dentro do espaco dele
    new_mob->x = x + w/2;
    new_mob->y = y + h/2;
    new_mob->w = w;
    new_mob->h = h;

    new_mob->max_x = range_x + x;
    new_mob->min_x = x;

    new_mob->step_size = step_size;
    new_mob->trajectory = GM_TRAJECTORY_RIGHT;

    return new_mob;
}

// melhorar esse if
void mob_move(Mob *mob) {
    if (mob->trajectory == GM_TRAJECTORY_RIGHT) {
        if (mob->x >= mob->max_x) {
            mob->trajectory = GM_TRAJECTORY_LEFT;
        }
    } else {
        if (mob->x <= mob->min_x) {
            mob->trajectory = GM_TRAJECTORY_RIGHT;
        }
    }

    mob->x += (mob->trajectory == GM_TRAJECTORY_RIGHT) ? mob->step_size : -mob->step_size;
}