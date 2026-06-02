#include <stdlib.h>

#include "plataform.h"
#include "player.h"
#include "geometry.h"

plataform *plataform_create(int x, int y, int width, int height) {
    plataform *new_plataform;
    if (! (new_plataform = malloc (sizeof (plataform))))
        return NULL;

    new_plataform->x = x;
    new_plataform->y = y;
    new_plataform->width = width;
    new_plataform->height = height;

    return new_plataform;
}

Hitbox plataform_get_hitbox(plataform *plataform) {
    return (Hitbox) {
        plataform->x,
        plataform->y,
        plataform->width,
        plataform->height
    };
}
