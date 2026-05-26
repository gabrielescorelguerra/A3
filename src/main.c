#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>

#include <stdio.h>

#include "player.h"
#include "constants.h"
#include "movement.h"
#include "joystick.h"

#define FRAME_RATE 60

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
    ALLEGRO_DISPLAY* disp = al_create_display(GM_SCREEN_X, GM_SCREEN_Y);

    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_display_event_source(disp));	
    al_register_event_source(queue, al_get_timer_event_source(timer));

    // cria player
    player *player = player_create ();
    if (!player)
        return -1;
    ALLEGRO_BITMAP *player_bitmap = al_load_bitmap("assets/player.png");

    ALLEGRO_BITMAP *background_bitmap = al_load_bitmap("assets/teste.jpg");

    // execução
    ALLEGRO_EVENT event;
    al_start_timer(timer);
    while(1) {
        al_wait_for_event(queue, &event);

        if (event.type == ALLEGRO_EVENT_TIMER) {
            update_position_player(player);

            int center = GM_SCREEN_X/2 - player->width/2;
            int x_bg = - player->x + center;

            // FUNDO
            al_clear_to_color(al_map_rgb(0, 0, 0));
            // depois ver como colocar melhor esses valores

            // fazer com ? : ou case switch ou funcao local de renderizacao
            if (player->x < center) {
                al_draw_scaled_bitmap(background_bitmap, 0, 0, 720, 360, 0, 0, GM_BACKGROUND_X, GM_SCREEN_Y, 0);
                al_draw_bitmap(player_bitmap, player->x, player->y, 0);
            } else if (player->x > (GM_BACKGROUND_X - GM_SCREEN_X)) {
                al_draw_scaled_bitmap(background_bitmap, 0, 0, 720, 360, center - (GM_BACKGROUND_X - GM_SCREEN_X), 0, GM_BACKGROUND_X, GM_SCREEN_Y, 0);
                al_draw_bitmap(player_bitmap, player->x - (GM_BACKGROUND_X - GM_SCREEN_X) + center, player->y, 0);
            } else {
                al_draw_scaled_bitmap(background_bitmap, 0, 0, 720, 360, x_bg, 0, GM_BACKGROUND_X, GM_SCREEN_Y, 0);
                al_draw_bitmap(player_bitmap, center, player->y, 0); 
            }
            al_flip_display();
        }

        // registra movimentos
        if (event.type == ALLEGRO_EVENT_KEY_DOWN || event.type == ALLEGRO_EVENT_KEY_UP) {
            switch (event.keyboard.keycode) {
            case ALLEGRO_KEY_UP:
                joystick_up(player->control);
                break;
            case ALLEGRO_KEY_RIGHT:
                joystick_right(player->control);
                break;
            case ALLEGRO_KEY_DOWN:
                joystick_down(player->control);
                break;
            case ALLEGRO_KEY_LEFT:
                joystick_left(player->control);
                break;
            }
        }

        else if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) break;	
    }

    al_destroy_bitmap(player_bitmap);
    al_destroy_bitmap(background_bitmap);

    al_destroy_font(font);
    al_destroy_display(disp);
    al_destroy_timer(timer);
    al_destroy_event_queue(queue);

    return 0;
}