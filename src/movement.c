#include "player.h"
#include "constants.h"

void update_position_player(player *player){		
    /* if (player->control->up) {
        player_move (player, 1, GM_TRAJECTORY_UP, GM_WORLD_W, GM_SCREEN_H);
    } */
    if (player->control->right) {
        player_move (player, 1, GM_TRAJECTORY_RIGHT, GM_WORLD_W, GM_SCREEN_H);
    }
    /* if (player->control->down && !(player->grounded)) {
        player->vy = GM_GRAVITY;
    } */
    if (player->control->left) {
        player_move (player, 1, GM_TRAJECTORY_LEFT, GM_WORLD_W, GM_SCREEN_H);
    }

    if (player->control->jump && (player->grounded)) {
        player->vy -= GM_PLAYER_JUMP_SPEED;
        player->grounded = 0;
    }

    // update gravity
    if (!player->grounded) {
        player->vy += GM_GRAVITY;
        player->y += player->vy;    
    }
}