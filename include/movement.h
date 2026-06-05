#ifndef MOVEMENT_H
#define MOVEMENT_H

#include "player.h"

// atualiza a posicao de um corpo
void update_position_body(PhysicsBody *body, Trajectory trajectory, int min, int max);

// calcula vy e atualiza posicao vertical do corpo caso nao esteja em pe sob algo
void update_gravity_body(PhysicsBody *body, int min_y, int max_y);

#endif