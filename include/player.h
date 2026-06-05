#ifndef PLAYER_H
#define PLAYER_H

#include "joystick.h"
#include "physics.h"
#include "constants.h"

#include "physics.h"
#include "sprite.h"

typedef struct {
    PhysicsBody body;
    Sprite sprite;
    joystick control;
} Player;

Player *player_create (float x, float y, int w, int h, Sprite sprite);
void player_move (Player *player);
void player_destroy(Player *player);

#endif