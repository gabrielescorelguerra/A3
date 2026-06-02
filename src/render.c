#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>

#include "render.h"
#include "player.h"
#include "constants.h"

void render_player(player *player, ALLEGRO_BITMAP *player_bitmap_sheet, int camera_x) {
    // fazer switch so mudar o bitmap ja q o resto n muda
    switch (player->anim)
    {
    case ANIM_IDLE:
        al_draw_bitmap_region(
            player_bitmap_sheet,
            0, GM_PLAYER_HEIGHT*4,
            GM_PLAYER_WIDTH, GM_PLAYER_HEIGHT,
            player->x - camera_x - player->x/2, player->y - player->height/2,
            0
        );
        break;
    case ANIM_WALK:
        al_draw_bitmap_region(
            player_bitmap_sheet,
            0, 0,
            GM_PLAYER_WIDTH, GM_PLAYER_HEIGHT,
            player->x - camera_x - player->x/2, player->y - player->height/2,
            0
        );
        break;
    default:
        al_draw_bitmap_region(
            player_bitmap_sheet,
            0, GM_PLAYER_HEIGHT*2,
            GM_PLAYER_WIDTH, GM_PLAYER_HEIGHT,
            player->x - camera_x - player->x/2, player->y - player->height/2,
            0
        );
        break;
    }
}