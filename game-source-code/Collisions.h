#ifndef D15E5CA8_19CC_4569_8BBC_70E46AD52EA7
#define D15E5CA8_19CC_4569_8BBC_70E46AD52EA7

#include <vector>
#include <memory>
#include <raylib-cpp.hpp>
#include <tuple>

using namespace std;

/**
 * @brief Handles collision detection between game objects.
 * 
 * The Collisions class provides methods for checking collisions
 * between different objects in the game.
 */
class Collisions {
public:
    Collisions() {};
    /**
     * @brief Checks for collisions between two sets of objects.
     * 
     * @tparam T1 Type of the first object.
     * @tparam T2 Type of the second object.
     * @param Object Vector of shared pointers to objects.
     * @param Player Shared pointer to the player object.
     */
    template <typename T1, typename T2>
    void checkCollisions(vector<shared_ptr<T1>> Object, shared_ptr<T2> Player);
    
    /**
     * @brief Gets the collision status.
     * 
     * @return true if a collision occurred, false otherwise.
     */
    bool getCollision();
    
    /**
     * @brief Gets the index of the colliding object.
     * 
     * @return int The index of the colliding object.
     */
    int getObject();
    
    /**
     * @brief Resets the collision status.
     */
    void resetCollision();

    /**
     * @brief Returns the bounding rectangle of an object.
     * 
     * @tparam T Type of the object.
     * @param Object Shared pointer to the object.
     * @return Rectangle The bounding rectangle of the object.
     */
    template <typename T>
    Rectangle returnRect(shared_ptr<T> Object);

private:
    tuple<bool, int> CollisionObject; ///< Stores collision state and object index.
};

template <typename T1, typename T2>
void Collisions::checkCollisions(vector<shared_ptr<T1>> Object, shared_ptr<T2> Player) {
    for (int i = 0; i < Object.size(); i++) {
        if (CheckCollisionRecs(returnRect(Object[i]), Player->getBoundingBox())) {
            get<0>(CollisionObject) = true;
            get<1>(CollisionObject) = i;
            break;
        }
    }
}

template <typename T>
Rectangle Collisions::returnRect(shared_ptr<T> Object) {
    return {(float)Object->get_x(), (float)Object->get_y(), (float)Object->getWidth(), (float)Object->getHeight()};
}

#endif /* D15E5CA8_19CC_4569_8BBC_70E46AD52EA7 */
