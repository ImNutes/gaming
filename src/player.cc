#include "player.hh"

#include <algorithm>
void Player::update() {
}

void Player::draw() {
    DrawCube((Vector3){0.0f, 0.0f, 0.0f}, 2.0, 2.0, 2.0, RED);
}