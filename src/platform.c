#include <stdlib.h>

#include "platform.h"
#include "physics.h"
#include "sprite.h"

// retorna plataforma
Platform *platform_create(float x, float y, int w, int h, Sprite *sprite) {
    Platform *new_platform;
    if (! (new_platform = malloc (sizeof (Platform))))
        return NULL;

    new_platform->hitbox.x = x;
    new_platform->hitbox.y = y;
    new_platform->hitbox.w = w;
    new_platform->hitbox.h = h;
    new_platform->sprite = *sprite;

    return new_platform;
}

void platform_destroy(Platform *platform) {
    free (platform);
}
