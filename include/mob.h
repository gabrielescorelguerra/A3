#ifndef MOB_H
#define MOB_H

#include "physics.h"
#include "sprite.h"
#include "constants.h"

typedef struct {
    PhysicsBody body;
    Sprite sprite;
    Trajectory trajectory;
    MobMovementType movement_type;
    float max_x, min_x, max_y, min_y;
    float speed;
} Mob;

Mob *mob_create(float x, float y, int w, int h, int range_x, int range_y, float speed, MobMovementType movement_type, Sprite *sprite);
void mob_move(Mob *mob);

#endif