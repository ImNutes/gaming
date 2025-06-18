#ifndef GAME_HH
#define GAME_HH

#include "raylib.h"

#include "objects.hh"

#include "player.hh"

const float SPAWNING_RADIUS = 5.0f;
const float SPAWNING_DISTANCE = 50.0f;
class Game {
public:
Game();

void updateDrawFrame();
void update();
void draw();

void updateCam();
private:
int frame;
Camera3D camera;
Player player;
ObjectsManager objects;
};

#endif
