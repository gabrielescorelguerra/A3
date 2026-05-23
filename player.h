#ifndef PLAYER_H
#define PLAYER_H

#include "joystick.h"

typedef struct {
    int height;
    int width;
    int x;
    int y;
    int step_size;
    joystick *control;
} player;

player *player_create(int x, int y);
void player_move(player *player, int steps, int trajectory, int max_x, int max_y);
void player_destroy(player *player);

#endif