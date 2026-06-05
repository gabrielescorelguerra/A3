#include "collision.h"
#include "physics.h"

int collision (Hitbox a, Hitbox b) {
    int a_top = a.y;
    int a_right = a.x + a.w;
    int a_bottom = a.y + a.h;
    int a_left = a.x;

    int b_top = b.y;
    int b_right = b.x + b.w;
    int b_bottom = b.y + b.h;
    int b_left = b.x;

    // sem sobreposição não tem colisão
    if ((a_right <= b_left) || (a_left >= b_right) || (a_bottom <= b_top) || (a_top >= b_bottom))
        return 0;
    return 1;
    
}