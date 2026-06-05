#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>

#include <stdio.h>

// ver includes caso nao seja no vs code (pra ser tipo ../include/)

#include "player.h"
#include "constants.h"
#include "movement.h"
#include "joystick.h"
#include "physics.h"
#include "collision.h"
#include "platform.h"
#include "render.h"
#include "animations.h"
#include "mob.h"
#include "sprite.h"

#define FRAME_RATE 30

#define TEST_PLAT_X 0
#define TEST_PLAT_Y GM_SCREEN_H - 70
#define TEST_PLAT_W GM_WORLD_W
#define TEST_PLAT_H 70

// talvez adicionar must_init

int main() {
    al_init();
    al_init_primitives_addon();		
    al_init_image_addon();
    al_install_keyboard();
    // depois mouse eu imagino

    // cria relogio, fila de eventos, fonte e janela
    ALLEGRO_TIMER *timer = al_create_timer (1.0 / FRAME_RATE);
    ALLEGRO_EVENT_QUEUE* queue = al_create_event_queue();
    ALLEGRO_FONT* font = al_create_builtin_font();
    ALLEGRO_DISPLAY* disp = al_create_display(GM_SCREEN_W, GM_SCREEN_H);

    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_display_event_source(disp));	
    al_register_event_source(queue, al_get_timer_event_source(timer));

    // cria plataforma

    ALLEGRO_BITMAP *background_bitmap = al_load_bitmap("assets/bg.png");
    Sprite *background_sprite = sprite_create(background_bitmap, 1, 1, 1, GM_WORLD_W, GM_SCREEN_H);
    Platform *platform = platform_create (TEST_PLAT_X, TEST_PLAT_Y, TEST_PLAT_W, TEST_PLAT_H, background_sprite);

    // cria mob
    ALLEGRO_BITMAP *mob_bitmap = al_load_bitmap("assets/mob.png");
    Sprite *mob_sprite = sprite_create(mob_bitmap, 1, 1, 1, 128, 128);
    Mob *mob = mob_create (400, 400, 128, 128, 200, 0, 2, GM_MOB_PATROL_X, mob_sprite);

    // cria player
    ALLEGRO_BITMAP *player_bitmap_sheet = al_load_bitmap("assets/player.png");
    Sprite *player_sprite = sprite_create(player_bitmap_sheet, 1, 1, 1, 128, 128);
    // ajeitar e fzr ser player_sprite e nao *player_sprite
    Player *player = player_create(0, 60, 128, 128, *player_sprite);

    // camera
    int camera_x;

    // execução
    ALLEGRO_EVENT event;
    al_start_timer(timer);
    while(1) {
        al_wait_for_event(queue, &event);

        if (event.type == ALLEGRO_EVENT_TIMER) {

            int old_player_x = player->body.hitbox.x;
            int old_player_y = player->body.hitbox.y;

            // updates
            player_move(player);
            mob_move(mob);
            update_gravity_body(&player->body, 0, GM_SCREEN_H);
            update_gravity_body(&mob->body, 0, GM_SCREEN_H);

            al_clear_to_color(al_map_rgb(0, 0, 0));

            Hitbox player_hitbox = player->body.hitbox;
            Hitbox platform_hitbox = platform->hitbox;

            if (collision (player_hitbox, platform_hitbox)) {
                player->body.hitbox.y = platform_hitbox.y - player_hitbox.h;
                player->body.grounded = 1;
                player->body.vy = 0;
            }  else {
                player->body.grounded = 0;
            }

            // camera
            camera_x = player->body.hitbox.x - GM_CAMERA_TRIGGER_X;;
            if (camera_x < 0)
                camera_x = 0;
            if (camera_x > GM_WORLD_W - GM_SCREEN_W)
                camera_x = GM_WORLD_W - GM_SCREEN_W;

            // render
            al_draw_scaled_bitmap(background_bitmap, 0, 0, 1024, 128, -camera_x, 0, GM_WORLD_W, GM_SCREEN_H, 0);
            //animation_update(player);
            render_player(player, player_bitmap_sheet, camera_x);
            render_mob(mob, mob_bitmap, camera_x);

            // teste
            /*
            al_draw_filled_rectangle(
                TEST_PLAT_X - TEST_PLAT_W/2 - camera_x,
                TEST_PLAT_Y - TEST_PLAT_H/2,
                TEST_PLAT_X + TEST_PLAT_W/2 - camera_x,
                TEST_PLAT_Y + TEST_PLAT_H/2,
                al_map_rgb(255,255,255)
            );*/

            al_flip_display();
        }

        // registra movimentos
        if (event.type == ALLEGRO_EVENT_KEY_DOWN || event.type == ALLEGRO_EVENT_KEY_UP) {
            switch (event.keyboard.keycode) {
                case ALLEGRO_KEY_UP:
                    joystick_up(&player->control);
                    break;
                case ALLEGRO_KEY_RIGHT:
                    joystick_right(&player->control);
                    break;
                case ALLEGRO_KEY_DOWN:
                    joystick_down(&player->control);
                    break;
                case ALLEGRO_KEY_LEFT:
                    joystick_left(&player->control);
                    break;
                case ALLEGRO_KEY_SPACE:
                    (event.type == ALLEGRO_EVENT_KEY_DOWN) ? joystick_jump_hold(&player->control) : joystick_jump_release(&player->control);
                    break;
            }
        }

        else if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) break;	
    }

    al_destroy_bitmap(player_bitmap_sheet);
    al_destroy_bitmap(background_bitmap);

    al_destroy_font(font);
    al_destroy_display(disp);
    al_destroy_timer(timer);
    al_destroy_event_queue(queue);

    return 0;
}