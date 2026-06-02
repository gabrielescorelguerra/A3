#include <stdlib.h>

#include "platform.h"
#include "player.h"
#include "geometry.h"

platform *platform_create(int x, int y, int width, int height) {
    platform *new_platform;
    if (! (new_platform = malloc (sizeof (platform))))
        return NULL;

    new_platform->x = x;
    new_platform->y = y;
    new_platform->width = width;
    new_platform->height = height;

    return new_platform;
}

Hitbox platform_get_hitbox(platform *platform) {
    return (Hitbox) {
        platform->x,
        platform->y,
        platform->width,
        platform->height
    };
}
