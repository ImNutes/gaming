#include "game.hh"

#include <string>
Game::Game() : frame{0}, camera{}, player{(Vector3){0.0f, 0.0f, 0.0f}}, objects{} {
    camera.up = (Vector3){0.0f, 1.0f, 0.0f};
    camera.fovy = 80.0f;
    camera.projection = CAMERA_PERSPECTIVE;
    updateCam();

}

void Game::updateDrawFrame() {
    frame++;
    update();
    draw();
}

void Game::update() {
    if(IsKeyDown(KEY_RIGHT)) {
        objects.direction = -1;
    } else if(IsKeyDown(KEY_LEFT)) {
        objects.direction = 1;
    } else {
        objects.direction = 0;
    }
    if( frame % 45 == 0 ) {
        float left_bound = -SPAWNING_RADIUS;
        float right_bound = SPAWNING_RADIUS;

        WorldObject obj{ 1.0f, (Vector3){(float)GetRandomValue(left_bound, right_bound), 0.0f, -SPAWNING_DISTANCE}, (Vector3){ 2.0f, 2.0f, 2.0f}, CollisionType::BOX };
        objects.registerObject(obj);
    }
    objects.update(player.collision);
    player.update();
    updateCam();
}

void Game::draw() {
    BeginDrawing();
   ClearBackground(RAYWHITE);
    BeginMode3D(camera);
       objects.draw();
       player.draw();
       //DrawGrid(500, 1.0f);
    EndMode3D();

    DrawText("Raylib 3D a ", 10, 40, 20, DARKGRAY);
    DrawText( std::to_string( objects.getCount() ).c_str(), 10, 70, 20, DARKGRAY );
    EndDrawing();
}

void Game::updateCam() {
    camera.position = (Vector3){0.0f, 5.0f, 10.0f};
    camera.target = (Vector3){0.0f, 1.0f, 0.0f};
}
