#ifndef PLAYER_H
#define PLAYER_H

#include "joystick.h"
#include "geometry.h"
#include "constants.h"

typedef struct {
    int height;
    int width;

    int x;
    int y;

    float vy;
    int step_size;
    int grounded;

    AnimState anim;

    joystick *control;
} player;

player *player_create();
void player_move(player *player, int steps, int trajectory, int max_x, int max_y);
Hitbox player_get_hitbox(player *player);
void player_destroy(player *player);

#endif