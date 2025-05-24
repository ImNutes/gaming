#include <emscripten.h>
#include "raylib.h"
#include "rlgl.h"
#include <iostream>

void UpdateDrawFrame();

Camera3D camera = {0};
Vector3 cubePosition = { 0.0f, 1.0f, 0.0f };
Shader world_shader;
int main() {
    const int SCREEN_WIDTH = 800;
    const int SCREEN_LENGTH = 800;
    InitWindow(SCREEN_WIDTH, SCREEN_LENGTH, "hi from raylib");

    camera.position = (Vector3){0.0f, 7.0f, 10.0f};
    camera.target = (Vector3){0.0f, 0.0f, 0.0f};
    camera.up = (Vector3){0.0f, 1.0f, 0.0f};
    camera.fovy = 80.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    #if defined(PLATFORM_WEB)
        emscripten_set_main_loop(UpdateDrawFrame, 60, 1);
    #else
        #error "HELL NAH"
        SetTargetFPS(60);
    #endif
    while(!WindowShouldClose()) {
        UpdateDrawFrame();
    }

    CloseWindow();
    return 0;
}
void UpdateDrawFrame() {
    BeginDrawing();
        ClearBackground(RAYWHITE);
        BeginMode3D(camera);
            DrawCube(cubePosition, 2.0f, 2.0f, 2.0f, RED);
            DrawCubeWires(cubePosition, 2.0f, 2.0f, 2.0f, MAROON);
            DrawGrid(10, 1.0f);
        EndMode3D();
        if(IsKeyDown(KEY_UP)) {
            camera.position.y += 5.0f;
        } else if(IsKeyDown(KEY_DOWN)) {
            camera.position.y -= 5.0f;
        }
        DrawText("Raylib 3D gaming", 10, 40, 20, DARKGRAY);
        DrawFPS(10, 10);
    EndDrawing();
}