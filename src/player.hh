#ifndef PLAYER_HH
#define PLAYER_HH

#include "raylib.h"
#include "raymath.h"

const float ACCEL = 0.2f;
const float MAX_SPEED = 2.0f;
struct Player {
    Vector3 position;
    Vector3 velocity;
    float accel;
    int direction; //should be -1, 0, or 1

    BoundingBox collision;

    void update();
    void draw();
};

#endif