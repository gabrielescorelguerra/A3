#ifndef RENDER_H
#define RENDER_H

#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>

#include "player.h"

void render_player(player *player, ALLEGRO_BITMAP *player_bitmap_sheet, int camera_x);

#endif