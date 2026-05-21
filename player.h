#ifndef PLAYER_H
#define PLAYER_H

typedef struct {
    unsigned char height;
    unsigned char width;
    unsigned short x;
    unsigned short y;
} player;

player *player_create(unsigned short x, unsigned short y);
void player_move(player *p, unsigned char steps, unsigned char trajectory, unsigned short max_x, unsigned short max_y);
void player_destroy(player *p);

#endif