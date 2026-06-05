#ifndef PLATAFORM_H
#define PLATAFORM_H

#include "physics.h"
#include "sprite.h"

// plataforma
typedef struct {
    Hitbox hitbox;
    Sprite sprite;
} Platform;
    
// retorna plataforma
Platform *platform_create(float x, float y, int w, int h, Sprite *sprite);

// destruir plataforma
void platform_destroy(Platform *platform);

#endif