#include <stdlib.h>

#include "player.h"
#include "joystick.h"
#include "constants.h"
#include "geometry.h"

player *player_create() {
    player *new_player;
    if (! (new_player = malloc(sizeof (player))))
        return NULL;

    new_player->width = GM_PLAYER_WIDTH;
    new_player->height = GM_PLAYER_HEIGHT;

    new_player->x = 0 + new_player->width/2;
    new_player->y = 0 + new_player->height/2;

    new_player->vy = 0.0;
    new_player->step_size = GM_WALK_STEP;
    new_player->grounded = 0;

    new_player->anim = ANIM_IDLE;

    // depois codigo especifico de erro AJEITAR
    new_player->control = joystick_create();
    if (!(new_player->control))
        return NULL;

    return new_player;
}

// tenho que ajeitar pro pulo
void player_move(player *player, int steps, int trajectory, int max_x, int max_y) {
    int x = player->x;
    int y = player->y;
    int width = player->width;
    int height = player->height;

    int distance = steps * player->step_size;

    switch (trajectory) {
    /*case GM_TRAJECTORY_UP:
        if ((player->y - player->height/2 - distance) > 0)
            player->y -= distance;
        break;*/
    case GM_TRAJECTORY_RIGHT:
        if ((player->x + player->width/2 + distance) < max_x)
            player->x += distance;
        break;
    /*case GM_TRAJECTORY_DOWN:
        if ((player->y + player->height/2 + distance) < max_y)
            player->y += distance;
        break;*/
    case GM_TRAJECTORY_LEFT:
        if ((player->x - player->width/2 - distance) > 0)
            player->x -= distance;
        break;
    }

    // update y
    player->y += player->vy;
}


// retorna area de colisao do player
Hitbox player_get_hitbox(player *player) {
    return (Hitbox){
        player->x,
        player->y,
        player->width,
        player->height
    };
}


// destroy
void player_destroy(player *player) {
    joystick_destroy (player->control);
    free (player);
}