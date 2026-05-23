#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>

#include <stdio.h>

#include "player.h"
#include "constants.h"
#include "movement.h"
#include "joystick.h"

#define FRAME_RATE 60

int main() {
    al_init();
    al_init_primitives_addon();		

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
    player *player = player_create (0, 0);
    if (!player)
        return -1;

    // execução
    ALLEGRO_EVENT event;
    al_start_timer(timer);
    while(1) {
        al_wait_for_event(queue, &event);

        if (event.type == ALLEGRO_EVENT_TIMER) {
            update_position_player(player);

            al_clear_to_color(al_map_rgb(0, 0, 0));	
            al_draw_filled_rectangle(player->x, player->y, player->x + player->width, player->y + player->height, al_map_rgb(255, 255, 255));		
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

    al_destroy_font(font);
    al_destroy_display(disp);
    al_destroy_timer(timer);
    al_destroy_event_queue(queue);

    return 0;
}