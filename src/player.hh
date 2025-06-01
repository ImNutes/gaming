#ifndef PLAYER_HH
#define PLAYER_HH

#include "raylib.h"
#include "raymath.h"

struct Player {

    BoundingBox collision;

    void update();
    void draw();
};

#endif