#ifndef JOYSTICK_H
#define JOYSTICK_H

#include "joystick.h"

typedef struct {
    unsigned char up;
    unsigned char right;
    unsigned char down;
    unsigned char left;
} joystick;

joystick *joystick_create();
void joystick_destroy(joystick *joystick);
void joystick_up(joystick *joystick);
void joystick_right(joystick *joystick);
void joystick_down(joystick *joystick);
void joystick_left(joystick *joystick);

#endif