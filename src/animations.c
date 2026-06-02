#include "animations.h"
#include "player.h"

#include "constants.h"

void animation_update(player *player) {
    if (!player->grounded) {
        if (player->vy < 0)
            player->anim = ANIM_JUMP;
        else
            player->anim = ANIM_FALL;
    }
    else if (player->control->left || player->control->right) {
            player->anim = ANIM_WALK;
    } else 
            player->anim = ANIM_IDLE; //ajejtiea
}