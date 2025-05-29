#include "objects.hh"
#include <iostream>
//returns false if object is now flagged for deletion
bool ObjectsManager::updateObject(WorldObject &obj) {
    std::cout << "tf";
    obj.position.z += m_worldspeed * obj.worldspeed;
    if(obj.position.z > WORLD_LIMIT)
        return false;
    return true;
}

void ObjectsManager::update() {
    for(size_t i = 0; i < m_world_objects.size(); ++i) {
        if(!updateObject(m_world_objects[i])) {
            m_world_objects.erase(m_world_objects.begin() + i);
        }
    }
}

size_t ObjectsManager::registerObject(WorldObject obj) {
    m_world_objects.push_back(obj);
    return m_world_objects.size() - 1;
}

void ObjectsManager::destroyObject(size_t i) {
    m_world_objects.erase(m_world_objects.begin() + i);
}

void ObjectsManager::drawObject(WorldObject obj) {
    DrawCube(obj.position, 2.0f, 2.0f, 2.0f, BLACK);
}

void ObjectsManager::draw() {
    for(auto i : m_world_objects)
        drawObject(i);
}