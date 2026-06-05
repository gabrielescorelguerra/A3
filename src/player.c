#include <stdlib.h>

#include "player.h"
#include "joystick.h"
#include "constants.h"
#include "physics.h"
#include "movement.h"

// depois fazer ser *sprite e nao sprite
// dps talvez usar speed e nao vx
Player *player_create (float x, float y, int w, int h, Sprite sprite) {
    Player *new_player;
    if (! (new_player = malloc (sizeof (Player))))
        return NULL;

    new_player->body = physics_body_create (x, y, 10, 0, w, h);
    new_player->sprite = sprite;
    new_player->control = joystick_create();

    return new_player;
}

// VER QND QUE MUDA VX

// BOM USAR GM_NO_LIMIT AO INVES DE 0
void player_move (Player *player) {

    int min_x = 0, min_y = 0;
    int max_x = GM_WORLD_W, max_y = GM_SCREEN_H;

    // ir para os lados
    if (player->control.right) {
        update_position_body (&player->body, GM_TRAJECTORY_RIGHT, min_x, max_x);
    }
    if (player->control.left) {
        update_position_body (&player->body, GM_TRAJECTORY_LEFT, min_x, max_x);
    }

    // jump
    if (player->control.jump && player->body.grounded) {
        player->body.vy = -GM_PLAYER_JUMP_SPEED;
        player->body.grounded = 0;
    }
    // ver se precisa
    update_gravity_body (&player->body, min_y, max_y);
}


// destroy
void player_destroy(Player *player) {
    free (player);
}