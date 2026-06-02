#include "collision.h"
#include "geometry.h"


int collision (Hitbox a, Hitbox b) {
    int a_top = a.y - a.height/2;
    int a_right = a.x + a.width/2;
    int a_bottom = a.y + a.height/2;
    int a_left = a.x - a.width/2;

    int b_top = b.y - b.height/2;
    int b_right = b.x + b.width/2;
    int b_bottom = b.y + b.height/2;
    int b_left = b.x - b.width/2;

    // sem sobreposição não tem colisão
    if ((a_right <= b_left) || (a_left >= b_right) || (a_bottom <= b_top) || (a_top >= b_bottom))
        return 0;
    return 1;
    
}