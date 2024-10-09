#ifndef DCFC5681_4E68_4E0A_AF25_1C9FDF03378B
#define DCFC5681_4E68_4E0A_AF25_1C9FDF03378B

#include "FileReader.h"
#include "player.h"
#include "Ghost.h"
#include "Key.h"
#include "Fruit.h"
#include "Score.h"
#include "Star.h"
#include "Wall.h"
#include "PowerPellet.h"

/**
 * @brief Manages game objects and their interactions.
 * 
 * The ObjectManager class handles the loading and retrieval of game objects.
 */
class ObjectManager {
public:
    ObjectManager() {};
    
    /**
     * @brief Loads objects from the specified file.
     * 
     * @param filepath The path to the file containing object data.
     */
    void loadObjects(string filepath);
    
    /**
     * @brief Retrieves an object by its type.
     * 
     * @tparam T The type of the object.
     * @param type The type of object to retrieve.
     * @return shared_ptr<T> The requested object.
     */
    template <typename T>
    shared_ptr<T> get(string type);

private:
    FileReader ObjectFile; ///< FileReader for object data.
    shared_ptr<player> playerPacman; ///< The player object.
    vector<shared_ptr<Ghost>> ghosts; ///< Vector of ghost objects.
    vector <shared_ptr<Wall>> walls; ///< Vector of wall objects.
    vector <shared_ptr<Wall>> boundaries; ///< Vector of boundary objects.
    vector<shared_ptr<Key>> keys; ///< Vector of key objects.
    vector<shared_ptr<Door>> doors; ///< Vector of door objects.
    vector<shared_ptr<Fruit>> fruits; ///< Vector of fruit objects.
    shared_ptr<Score> scores; ///< Score object.
    vector<shared_ptr<Star>> stars; ///< Vector of star objects.
    vector<shared_ptr<PowerPellet>> powerpellets; ///< Vector of power pellet objects.
};

template <typename T>
shared_ptr<T> ObjectManager::get(string type) {
    if (type == "player") {
        return playerPacman;
    } else if (type == "Ghost") {
        auto ghostPointer = make_shared<vector<shared_ptr<Ghost>>>(ghosts);
        return ghostPointer;
    } else if (type == "Wall") {
        auto wallPointer = make_shared<vector<shared_ptr<Wall>>>(walls);
        return wallPointer;
    } else if (type == "Boundary") {
        auto boundaryPointer = make_shared<vector<shared_ptr<Wall>>>(boundaries);
        return boundaryPointer;
    } else if (type == "Key") {
        auto keyPointer = make_shared<vector<shared_ptr<Key>>>(keys);
        return keyPointer;
    } else if (type == "Door") {
        auto doorPointer = make_shared<vector<shared_ptr<Door>>>(doors);
        return doorPointer;
    } else if (type == "Fruit") {
        auto fruitPointer = make_shared<vector<shared_ptr<Fruit>>>(fruits);
        return fruitPointer;
    } else if (type == "Score") {
        return scores;
    } else if (type == "Star") {
        auto starPointer = make_shared<vector<shared_ptr<Star>>>(stars);
        return starPointer;
    } else if (type == "PowerPellet") {
        auto powerpelletsPointer = make_shared<vector<shared_ptr<PowerPellet>>>(powerpellets);
        return powerpelletsPointer;
    } else {
        throw runtime_error("Type does not match any objects");
    }
}

#endif /* DCFC5681_4E68_4E0A_AF25_1C9FDF03378B */
