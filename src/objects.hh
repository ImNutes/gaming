#ifndef OBJECTS_HH
#define OBJECTS_HH
#include <vector>

#include "player.hh"

const size_t MAX_ENTITY_COUNT = 500;
const int WORLD_LIMIT = 250;

enum CollisionType { BOX, SPHERE };

struct WorldObject {
float worldspeed;
Vector3 position;

Vector3 collisionBoxSize;
};


//manages stuff in the world (but not the player)
class ObjectsManager {
public:
ObjectsManager(std::vector<WorldObject> obj = std::vector<WorldObject>()) : m_world_objects{obj}, m_worldspeed{1} {};

void setWorldSpeed(int worldspeed) { m_worldspeed = worldspeed; }

int checkCollision(BoundingBox thing); //returns the id of the obstacle that was hit

size_t registerObject(WorldObject obj);
void destroyObject(size_t i);

bool updateObject(WorldObject &obj);
void update();

void drawObject(WorldObject obj);
void draw();

size_t getCount() { return m_world_objects.size(); }
private:
std::vector<WorldObject> m_world_objects;
float m_worldspeed;
};

#endif