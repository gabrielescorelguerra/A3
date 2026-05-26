#ifndef CONSTANTS_H
#define CONSTANTS_H

enum Trajectories {
    GM_TRAJECTORY_UP = 0,
    GM_TRAJECTORY_RIGHT = 1,
    GM_TRAJECTORY_DOWN = 2,
    GM_TRAJECTORY_LEFT = 3
};

#define GM_WALK_STEP 10
#define GM_PLAYER_WIDTH 128
#define GM_PLAYER_HEIGHT 128

#define GM_SCREEN_X 1280
#define GM_SCREEN_Y 720

#define GM_VEL_X 5
#define GM_CAMERA_X = 0

#define GM_BACKGROUND_X (GM_SCREEN_X * 4)

#endif