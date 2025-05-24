#ifndef PLAYER_HH
#define PLAYER_HH

#include "raylib.h"

struct Player {
    BoundingBox collision;
    Vector3 position;
    Vector3 velocity;
    float accel;
};

struct Obstacle {
    BoundingBox collision;
    Vector3 position;
    float speed;
};


#endif