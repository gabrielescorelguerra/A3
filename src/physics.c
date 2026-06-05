#include "physics.h"

PhysicsBody physics_body_create (float x, float y, float vx, float vy, int w, int h) {
    PhysicsBody new_body;

    new_body.hitbox.x = x;
    new_body.hitbox.y = y;
    new_body.hitbox.w = w;
    new_body.hitbox.h = h;

    new_body.vx = vx;
    new_body.vy = vy;

    int grounded = 0;

    return new_body;
}