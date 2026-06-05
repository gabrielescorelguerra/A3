#ifndef CONSTANTS_H
#define CONSTANTS_H

// fazer typedef e tirar =

typedef enum {
    GM_TRAJECTORY_UP = 0,
    GM_TRAJECTORY_RIGHT = 1,
    GM_TRAJECTORY_DOWN = 2,
    GM_TRAJECTORY_LEFT = 3
} Trajectory;

typedef enum {
    GM_MOB_PATROL_X,
    GM_MOB_CHASE
} MobMovementType;

/*
typedef enum AnimState {
    ANIM_IDLE,
    ANIM_WALK_FOWARD,
    ANIM_WALK_BACKWARD,
    ANIM_JUMP_FOWARD,
    ANIM_JUMP_BACKWARD,
    ANIM_JUMP_IDLE,
    ANIM_FALL
} AnimState;*/

/*
enum CollisionSide{
    GM_COLLISION_NONE,
    GM_COLLISION_UP,
    GM_COLLISION_DOWN,
    GM_COLLISION_LEFT,
    GM_COLLISION_RIGHT
};*/

// PLAYER

#define GM_WALK_STEP 10
#define GM_PLAYER_WIDTH 128
#define GM_PLAYER_HEIGHT 128
#define GM_PLAYER_JUMP_SPEED 10

// JANELA

#define GM_SCREEN_W 1280
#define GM_SCREEN_H 1000
#define GM_WORLD_W ((GM_SCREEN_H / 128) * 1024)

// CAMERA

#define GM_CAMERA_TRIGGER_X (GM_SCREEN_W/2)

// FISICA

#define GM_GRAVITY 0.5

#define GM_VEL_X 5

#endif