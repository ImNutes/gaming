#include "objects.hh"
#include <iostream>

BoundingBox getBoundingBoxFromSize(Vector3 pos, Vector3 size) {
    return (BoundingBox){
        (Vector3){ pos.x - size.x/2, pos.y - size.y/2, pos.z - size.y/2 },
        (Vector3){ pos.x + size.x/2, pos.y + size.y/2, pos.z + size.y/2}
    };
}
int ObjectsManager::checkCollision(BoundingBox b, WorldObject obj) {
    return CheckCollisionBoxes(b, 
        getBoundingBoxFromSize(obj.position, obj.collision_size));
}

//returns false if object is now flagged for deletion
bool ObjectsManager::updateObject(WorldObject &obj) {
    obj.position = Vector3Add(obj.position, velocity);
    obj.position.z += m_worldspeed * obj.worldspeed;
    if(obj.position.z > WORLD_LIMIT)
        return false;
    return true;
}

int ObjectsManager::update(BoundingBox b) {
    int res = -1;
    if(direction < 0) {
        velocity.x = std::max(MAX_SPEED * direction, velocity.x + (ACCEL * direction));
    } else if(direction > 0) {
        velocity.x = std::min(MAX_SPEED * direction, velocity.x + (ACCEL * direction));
    } else {
        if(velocity.x > 0) {
            velocity.x = std::max(0.0f, velocity.x - ACCEL);
        } else if(velocity.x < 0) {
            velocity.x = std::min(0.0f, velocity.x + ACCEL);
        }
    }

    relative_position = Vector3Add(relative_position, velocity);
    if(relative_position.x > PLANE_WIDTH/2) {
        relative_position.x = -PLANE_WIDTH/2;
        plane_index = (++plane_index + PLANES_COUNT/2) % PLANES_COUNT;
    } else if(relative_position.x < -PLANE_WIDTH/2) {
        relative_position.x = PLANE_WIDTH/2;
        plane_index = (--plane_index + PLANES_COUNT) % PLANES_COUNT;
    }
    if(relative_position.z < PLANE_LENGTH/2) {
        relative_position.z = PLANE_LENGTH/2;
        plane_offset = !plane_offset;
    }
    for(size_t i = 0; i < m_world_objects.size(); ++i) {
        if(!updateObject(m_world_objects[i])) {
            m_world_objects.erase(m_world_objects.begin() + i);
        } else if( checkCollision(b, m_world_objects[i]) ) {
            std::cout << "ouch";
            res = i;
        }
    }
    return res;
}

size_t ObjectsManager::registerObject(WorldObject obj) {
    m_world_objects.push_back(obj);
    return m_world_objects.size() - 1;
}

void ObjectsManager::destroyObject(size_t i) {
    m_world_objects.erase(m_world_objects.begin() + i);
}

void ObjectsManager::drawObject(WorldObject obj) {
    DrawCube(obj.position, obj.collision_size.x, obj.collision_size.y, obj.collision_size.z, BLACK);
}

void ObjectsManager::draw() {
    for(auto i : m_world_objects)
        drawObject(i);

    
}
