#include "objects.hh"


void ObstaclesManager::updateObject(Obstacle obj) {
    obj.position.z += obj.speed * speed;
}