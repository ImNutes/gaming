#ifndef OBJECTS_HH
#define OBJECTS_HH
#include <vector>

#include "player.hh"

const size_t MAX_ENTITY_COUNT = 500;


class WorldObject {
    
};


//manages stuff in the world (but not the player)
class ObjectsManager {
public:
ObjectsManager(std::vector<WorldObject> obj = std::vector<WorldObject>()) : obj{obstacles} {};
void updateObject(WorldObject obj);
void update();
void drawObject(WorldObject obj);
void draw();
private:
std::vector<WorldObject> m_world_objects;
float m_worldspeed;
};

#endif
