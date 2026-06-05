#ifndef SPRITE_H
#define SPRITE_H

#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>

typedef enum AnimState {
    ANIM_IDLE,
    ANIM_WALK_FOWARD,
    ANIM_WALK_BACKWARD,
    ANIM_JUMP_FOWARD,
    ANIM_JUMP_BACKWARD,
    ANIM_JUMP_IDLE,
    ANIM_FALL
} AnimState;

typedef struct {
    ALLEGRO_BITMAP *bitmap;

    int frame;               // frame atual
    int frame_count;         // total de frames da animação atual
    int frame_timer;         // contador pra trocar frame
    int frame_speed;         // quantos ticks por frame

    int w;
    int h;

    AnimState state;
} Sprite;

Sprite *sprite_create(ALLEGRO_BITMAP *bitmap, int frame_count, int frame_timer, int frame_speed, int w, int h);

#endif