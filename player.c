#include <stdlib.h>
#include "player.h"
#include "trajectories.h"

player *player_create(unsigned short x, unsigned short y) {
    player *new_player;
    if (! (new_player = malloc(sizeof (player))))
        return NULL;

    new_player->x = x;
    new_player->y = y;
    new_player->width = 100;
    new_player->height = 100;

    return new_player;
}

void player_move(player *player, unsigned char steps, unsigned char trajectory, unsigned short max_x, unsigned short max_y) {
    switch (trajectory) {
    case TRAJECTORY_UP:
        /* code */
        break;
    case TRAJECTORY_RIGHT:

        break;
    case TRAJECTORY_DOWN:

        break;
    case TRAJECTORY_LEFT:
        break;
    }
}

void player_destroy(player *player) {
    free (player);
    player = NULL;
}