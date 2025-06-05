#ifndef OBJECTS_HH
#define OBJECTS_HH
#include <vector>

#include "player.hh"

const size_t MAX_ENTITY_COUNT = 500;
const int WORLD_LIMIT = 20;

const float ACCEL = 0.1f;
const float MAX_SPEED = 1.0f;

const size_t PLANES_COUNT = 6;
const float PLANE_WIDTH = 25.0f;
const float PLANE_LENGTH = 25.0f;


enum CollisionType { BOX, SPHERE };

struct WorldObject {
float worldspeed;
Vector3 position;

Vector3 collision_size;
CollisionType type;
};



/* Regarding plane display
 *____4_______5______6_____
 *____1_______2______3_____
 *____________X____________
 * as player moves to the right, 1 will go out of scope and be wrapped to the right of 3.
 * 
 */

//manages stuff in the world (but not the player)
class ObjectsManager {
public:
ObjectsManager() : m_world_objects{}, m_worldspeed{1} {

};

~ObjectsManager() {
}
void setWorldSpeed(int worldspeed) { m_worldspeed = worldspeed; }

int checkCollision(BoundingBox b, WorldObject obj);

size_t registerObject(WorldObject obj);
void destroyObject(size_t i);

bool updateObject(WorldObject &obj);
int update(BoundingBox b);

void drawObject(WorldObject obj);
void draw();

size_t getCount() { return m_world_objects.size(); }

int direction; //should be -1, 0, or 1

private:
std::vector<WorldObject> m_world_objects;
float m_worldspeed;

//handles the relative player movement
Vector3 velocity;

Model planes[PLANES_COUNT];
Vector3 relative_position; //location of the player in relation to the plane
size_t plane_index; //which plane the player is on
};

#endif
