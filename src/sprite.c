#include "sprite.h"

#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>

// vai ser chamado no main
Sprite *sprite_create(ALLEGRO_BITMAP *bitmap, int frame_count, int frame_timer, int frame_speed, int w, int h) {
    Sprite *new_sprite;
    if (! (new_sprite = malloc (sizeof (Sprite))))
        return NULL;

    new_sprite->bitmap = bitmap;

    new_sprite->frame = 0;
    new_sprite->frame_count = frame_count;
    new_sprite->frame_timer = frame_timer;
    new_sprite->frame_speed = frame_speed;

    new_sprite->w = w;
    new_sprite->h = h;

    return new_sprite;
}