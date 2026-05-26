#include <stdlib.h>

#include "player.h"
#include "joystick.h"
#include "constants.h"

#include "stdio.h"

player *player_create() {
    player *new_player;
    if (! (new_player = malloc(sizeof (player))))
        return NULL;

    new_player->x = 0;
    new_player->y = 0;
    new_player->width = GM_PLAYER_WIDTH;
    new_player->height = GM_PLAYER_HEIGHT;
    new_player->step_size = GM_WALK_STEP;

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
    case GM_TRAJECTORY_UP:
        player->y = (y - distance < 0) ? y : y - distance;
        break;
    case GM_TRAJECTORY_RIGHT:
        player->x = (x + width + distance > max_x) ? x : x + distance;
        break;
    case GM_TRAJECTORY_DOWN:
        player->y = (y + height + distance > max_y) ? y : y + distance;
        break;
    case GM_TRAJECTORY_LEFT:
        player->x = (x - distance < 0) ? x : x - distance;
        break;
    }
}

void player_destroy(player *player) {
    joystick_destroy (player->control);
    free (player);
}