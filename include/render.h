#ifndef RENDER_H
#define RENDER_H

#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>

#include "player.h"
#include "mob.h"

void render_player(Player *player, ALLEGRO_BITMAP *player_bitmap_sheet, int camera_x);
void render_mob (Mob *mob, ALLEGRO_BITMAP *player_bitmap_sheet, int camera_x);

#endif