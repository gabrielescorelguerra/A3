#include "player.h"
#include "constants.h"

void update_position_player(player *player){		
     // fazer constante pra limitemaximo horaizontal (largura do fundo)
    
    if (player->control->up) {
        player_move (player, 1, GM_TRAJECTORY_UP, GM_BACKGROUND_X, GM_SCREEN_Y);
    }
    if (player->control->right) {
        player_move (player, 1, GM_TRAJECTORY_RIGHT, GM_BACKGROUND_X, GM_SCREEN_Y);
    }
    if (player->control->down) {
        player_move (player, 1, GM_TRAJECTORY_DOWN, GM_BACKGROUND_X, GM_SCREEN_Y);
    }
    if (player->control->left) {
        player_move (player, 1, GM_TRAJECTORY_LEFT, GM_BACKGROUND_X, GM_SCREEN_Y);
    }
}