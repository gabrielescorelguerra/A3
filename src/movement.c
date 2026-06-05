#include "constants.h"
#include "physics.h"

// atualiza a posição de um corpo
void update_position_body(PhysicsBody *body, Trajectory trajectory, int min, int max) {
    Hitbox *hitbox = &body->hitbox;

    switch (trajectory)
    {
    case GM_TRAJECTORY_UP:
        if (hitbox->y - body->vy > min)
            hitbox->y -= body->vy;
        else
            hitbox->y = min;
        break;

    case GM_TRAJECTORY_RIGHT:
        if ((hitbox->x + hitbox->w + body->vx) < max)
            hitbox->x += body->vx;
        else
            hitbox->x = max - hitbox->w;
        break;

    case GM_TRAJECTORY_DOWN:
        if ((hitbox->y + hitbox->h + body->vy) < max)
            hitbox->y += body->vy;
        else
            hitbox->y = max - hitbox->h;
        break;

    case GM_TRAJECTORY_LEFT:
        if (hitbox->x - body->vx > min)
            hitbox->x -= body->vx;
        else 
            hitbox->x = min;
        break;

    default:
        break;
    }
}

void update_gravity_body(PhysicsBody *body, int min_y, int max_y) {
    if (! (body->grounded)) {
        body->vy += GM_GRAVITY;
        update_position_body(body, GM_TRAJECTORY_DOWN, min_y, max_y);
    } else {
        body->vy = 0;
    }
}