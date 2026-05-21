#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>

#include <stdio.h>

#include "player.h"

#define FRAME_RATE 20

int main() {
    al_init();
    al_init_primitives_addon();		

    al_install_keyboard();
    // depois mouse eu imagino

    // cria relogio, fila de eventos, fonte e janela
    ALLEGRO_TIMER *timer = al_create_timer (1.0 / FRAME_RATE);
    ALLEGRO_EVENT_QUEUE* queue = al_create_event_queue();
    ALLEGRO_FONT* font = al_create_builtin_font();
    ALLEGRO_DISPLAY* disp = al_create_display(800, 600);

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

        if (event.type == 30) {
            al_clear_to_color(al_map_rgb(0, 0, 0));	
            al_draw_filled_rectangle(player->x, player->y, player->x + player->width, player->y + player->height, al_map_rgb(255, 255, 255));		
            al_flip_display();
        }
        else if (event.type == 42) break;	
    }

    al_destroy_font(font);
    al_destroy_display(disp);
    al_destroy_timer(timer);
    al_destroy_event_queue(queue);

    return 0;
}