#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>

#include "render.h"
#include "player.h"
#include "constants.h"

void render_player(player *player, ALLEGRO_BITMAP *player_bitmap_sheet, int camera_x) {

    int bitmap_y;
    int tag = 0;

    // fazer switch so mudar o bitmap ja q o resto n muda
    switch (player->anim)
    {
    case ANIM_IDLE:
        bitmap_y = GM_PLAYER_HEIGHT*4;
        break;
    case ANIM_WALK_FOWARD:
        bitmap_y = 0;
        break;
    case ANIM_WALK_BACKWARD:
        bitmap_y = 0;
        tag = ALLEGRO_FLIP_HORIZONTAL;
        break;
    case ANIM_JUMP_FOWARD:
        bitmap_y = GM_PLAYER_HEIGHT*2;
        break;
    case ANIM_JUMP_BACKWARD:
        bitmap_y = GM_PLAYER_HEIGHT*2;
        tag = ALLEGRO_FLIP_HORIZONTAL;
        break;
    default:
        bitmap_y = GM_PLAYER_HEIGHT*4;
        break;
    }

    al_draw_bitmap_region(
        player_bitmap_sheet,
        0, bitmap_y,
        GM_PLAYER_WIDTH, GM_PLAYER_HEIGHT,
        + player->x - camera_x - player->width/2, player->y - player->height/2,
        tag
    );
}