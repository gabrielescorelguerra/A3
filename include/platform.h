#ifndef PLATAFORM_H
#define PLATAFORM_H

#include "player.h"

typedef struct {
    int x;
    int y;
    int width;
    int height;
} platform;

platform *platform_create(int x, int y, int width, int height);
Hitbox platform_get_hitbox(platform *platform);

#endif