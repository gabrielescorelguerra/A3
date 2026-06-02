#include "animations.h"
#include "player.h"

#include "constants.h"

void animation_update(player *player) {
    // refazer
    if (!player->grounded) {
        if (player->vy < 0) {
            if (player->control->right) {
                player->anim = ANIM_JUMP_FOWARD;
            }
            else if (player->control->left) {
                player->anim = ANIM_JUMP_BACKWARD;
            } else {
                player->anim = ANIM_JUMP_IDLE;
            }
        } else
            player->anim = ANIM_FALL;
    }
    else if (player->control->right) {
        player->anim = ANIM_WALK_FOWARD;
    }
    else if (player->control->left) {
        player->anim = ANIM_WALK_BACKWARD;
    } else 
            player->anim = ANIM_IDLE; //ajejtiea
}