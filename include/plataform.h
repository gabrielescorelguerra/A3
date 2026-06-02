#ifndef PLATAFORM_H
#define PLATAFORM_H

#include "player.h"

typedef struct {
    int x;
    int y;
    int width;
    int height;
} plataform;

plataform *plataform_create(int x, int y, int width, int height);
Hitbox plataform_get_hitbox(plataform *plataform);

#endif