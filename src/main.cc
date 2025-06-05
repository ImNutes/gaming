#if defined(PLATFORM_WEB)
#include <emscripten.h>
#endif
#include "raylib.h"
#include "rlgl.h"
#include <iostream>

#include "game.hh"

Game game{};
//is there a better way to do this
void doFrame() {
   game.updateDrawFrame(); 
}

int main() {
    const int SCREEN_WIDTH = 800;
    const int SCREEN_LENGTH = 800;
    InitWindow(SCREEN_WIDTH, SCREEN_LENGTH, "hi from raylib");

    #if defined(PLATFORM_WEB)
        emscripten_set_main_loop( doFrame, 60, 1);
    #else
        SetTargetFPS(60);
    while(!WindowShouldClose()) {
        doFrame();
    }
    #endif

    CloseWindow();
    return 0;
}
