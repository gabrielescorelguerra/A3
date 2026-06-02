#ifndef CONSTANTS_H
#define CONSTANTS_H

// fazer typedef e tirar =
enum Trajectories {
    GM_TRAJECTORY_UP = 0,
    GM_TRAJECTORY_RIGHT = 1,
    GM_TRAJECTORY_DOWN = 2,
    GM_TRAJECTORY_LEFT = 3
};

typedef enum AnimState {
    ANIM_IDLE,
    ANIM_WALK,
    ANIM_JUMP,
    ANIM_FALL
} AnimState;

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
#define GM_SCREEN_H 720
#define GM_WORLD_W (GM_SCREEN_W * 2)

// CAMERA

#define GM_CAMERA_TRIGGER_X (GM_SCREEN_W/2)

// FISICA

#define GM_GRAVITY 0.8

#define GM_VEL_X 5

#endif