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

class ObjectManager
{
    public:
        ObjectManager(){};
        void loadObjects(string filepath);
        template <typename T>
        shared_ptr<T> get(string type);
    private:
        FileReader ObjectFile;

        shared_ptr<player> playerPacman;
        vector<shared_ptr<Ghost>> ghosts;
        vector <shared_ptr<Wall>> walls;
        vector <shared_ptr<Wall>> boundaries;
        vector<shared_ptr<Key>> keys;
        vector<shared_ptr<Door>> doors;
        vector<shared_ptr<Fruit>> fruits;
        shared_ptr<Score> scores;
        vector<shared_ptr<Star>> stars;
        vector<shared_ptr<PowerPellet>> powerpellets;
};

template <typename T>
shared_ptr<T> ObjectManager::get(string type)
{
    if(type == "player")
    {
        return playerPacman;
    }
    else if(type == "Ghost")
    {
        auto ghostPointer = make_shared<vector<shared_ptr<Ghost>>>(ghosts);
        return ghostPointer;
    }
    else if(type == "Wall")
    {
        auto wallPointer = make_shared<vector<shared_ptr<Wall>>>(walls);
        return wallPointer;
    }
    else if(type == "Boundary")
    {
        auto boundaryPointer = make_shared<vector<shared_ptr<Wall>>>(boundaries);
        return boundaryPointer;
    }
    else if(type == "Key")
    {
        auto keyPointer = make_shared<vector<shared_ptr<Key>>>(keys);
        return keyPointer;
    }
    else if(type == "Door")
    {
        auto doorPointer = make_shared<vector<shared_ptr<Door>>>(doors);
        return doorPointer;
    }
    else if(type == "Fruit")
    {
        auto fruitPointer = make_shared<vector<shared_ptr<Fruit>>>(fruits);
        return fruitPointer;
    }
    else if(type == "Score")
    {
        return scores;
    }
    else if(type == "Star")
    {
        auto starPointer = make_shared<vector<shared_ptr<Star>>>(stars);
        return starPointer;
    }
    else if(type == "PowerPellet")
    {
        auto powerpelletsPointer = make_shared<vector<shared_ptr<PowerPellet>>>(powerpellets);
        return powerpelletsPointer;
    }
    else 
        throw runtime_error("Type does not match any objects");
}

#endif /* DCFC5681_4E68_4E0A_AF25_1C9FDF03378B */
