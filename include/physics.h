#ifndef PHYSICS_H
#define PHYSICS_H

// hitbox de colisao
typedef struct {
    float x;
    float y;
    int w;
    int h;
} Hitbox;

// corpo físico
typedef struct {
    Hitbox hitbox;
    float vx, vy;
    int grounded;
} PhysicsBody;

// criar corpo físico
PhysicsBody physics_body_create (float x, float y, float vx, float vy, int w, int h);

#endif