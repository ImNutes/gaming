#ifndef OBJECTS_HH
#define OBJECTS_HH
#include <vector>

#include "player.hh"

//I could also use ECS for this

template <typename T>
class ObjectManager {
public:
ObjectManager(std::vector<T> objects) : m_objects{objects} {}
int add(T obj) { m_objects.push_back(obj); return m_objects.size() - 1; }
T& get(int index) { return m_objects[index]; }
void remove(int index) {
    m_objects.erase(m_objects.begin() + index);
}
virtual void updateObject(T obj) = 0;
virtual void update() {
    for(auto i : m_objects) {
        updateObject(i);
    }
}

private:
std::vector<T> m_objects;
};

class ObstaclesManager : ObjectManager<Obstacle> {
public:
ObstaclesManager(std::vector<Obstacle> obj) : ObjectManager(obj) {}
void updateObject(Obstacle obj) override;
private:
float speed;
};

#endif
