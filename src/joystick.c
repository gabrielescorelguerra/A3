#include <stdlib.h>
#include "joystick.h"

joystick *joystick_create() {
    joystick *new_joystick;
    if (! (new_joystick = malloc (sizeof (joystick))))
        return NULL;

    new_joystick->up = 0;
    new_joystick->right = 0;
    new_joystick->down = 0;
    new_joystick->left = 0;

    new_joystick->jump = 0;

    return new_joystick;
}

void joystick_destroy(joystick *joystick) {
    free (joystick);
}

void joystick_up(joystick *joystick) {
    joystick->up ^= 1;
}

void joystick_right(joystick *joystick) {
    joystick->right ^= 1;
}

void joystick_down(joystick *joystick) {
    joystick->down ^= 1;
}

void joystick_left(joystick *joystick) {
    joystick->left ^= 1;
}

void joystick_jump_hold(joystick *joystick) {
    joystick->jump = 1;
}

void joystick_jump_release(joystick *joystick) {
    joystick->jump = 0;
}