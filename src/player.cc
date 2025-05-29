#include "player.hh"

#include <algorithm>
void Player::update() {
    if(direction < 0) {
        velocity.x = std::max(MAX_SPEED * direction, velocity.x + (ACCEL * direction));
    } else if(direction > 0) {
        velocity.x = std::min(MAX_SPEED * direction, velocity.x + (ACCEL * direction));
    } else {
        if(velocity.x < 0) {
            velocity.x = std::min(0.0f, velocity.x + ACCEL);
        } else if(velocity.x > 0) {
            velocity.x = std::max(0.0f, velocity.x - ACCEL);
        }
    }
    position = Vector3Add(position, velocity);
}

void Player::draw() {
    DrawCube(position, 2.0, 2.0, 2.0, RED);
}