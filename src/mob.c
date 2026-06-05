#include <stdlib.h>

#include "mob.h"
#include "constants.h"
#include "movement.h"

// x e y são o centro do movimento dele
Mob *mob_create(float x, float y, int w, int h, int range_x, int range_y, float speed, MobMovementType movement_type, Sprite *sprite) {
    Mob *new_mob;
    if (! (new_mob = malloc(sizeof (Mob))))
        return NULL;

    new_mob->body = physics_body_create(x, y, 0, 0, w, h);
    new_mob->sprite = *sprite;
    new_mob->trajectory = GM_TRAJECTORY_RIGHT;

    new_mob->movement_type = movement_type;

    new_mob->max_x = x + range_x;
    new_mob->min_x = x - range_x;
    new_mob->max_y = y + range_y;
    new_mob->min_y = y - range_y;

    new_mob->speed = speed;

    return new_mob;
}

Trajectory mob_define_trajectory(Mob *mob) {
    if (mob->movement_type == GM_MOB_PATROL_X) {
        if (mob->trajectory == GM_TRAJECTORY_RIGHT && (mob->body.hitbox.x + mob->body.hitbox.w) >= mob->max_x)
            return GM_TRAJECTORY_LEFT;
        if (mob->trajectory == GM_TRAJECTORY_LEFT && mob->body.hitbox.x <= mob->min_x)
            return GM_TRAJECTORY_RIGHT;
    }
    // dps fazer o de chase
    return mob->trajectory;
}

// melhorar esse if
void mob_move(Mob *mob) {
    // definir nova trajetoria do mob
    Trajectory new_trajectory = mob_define_trajectory(mob);
    mob->trajectory = new_trajectory;

    mob->body.vy = 0;
    mob->body.vx = 0;

    if (new_trajectory == GM_TRAJECTORY_RIGHT) {
        mob->body.vx = mob->speed;
        update_position_body(&mob->body, GM_TRAJECTORY_RIGHT, mob->min_x, mob->max_x);
    }
    if (new_trajectory == GM_TRAJECTORY_LEFT) {
        mob->body.vx = mob->speed;
        update_position_body(&mob->body, GM_TRAJECTORY_LEFT, mob->min_x, mob->max_x);
    }
    if (new_trajectory == GM_TRAJECTORY_UP) {
        mob->body.vy = mob->speed;
        update_position_body(&mob->body, GM_TRAJECTORY_UP, mob->min_y, mob->max_y);
    }
    if (new_trajectory == GM_TRAJECTORY_DOWN) {
        mob->body.vy = mob->speed;
        update_position_body(&mob->body, GM_TRAJECTORY_DOWN, mob->min_y, mob->max_y);
    }
}