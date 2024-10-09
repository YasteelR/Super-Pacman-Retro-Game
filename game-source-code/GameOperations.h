#ifndef CE167A85_A911_4D91_8B62_622EFB213774
#define CE167A85_A911_4D91_8B62_622EFB213774

#include <string>
#include <iostream>
#include <tuple>
#include "player.h"
#include "Ghost.h"
#include "FileReader.h"
#include "Key.h"
#include "Fruit.h"
#include "Score.h"
#include "Star.h"
#include "Move.h"
#include "Render.h"
#include "Wall.h"
#include "PowerPellet.h"
#include "Collisions.h"
#include "SuperPellet.h"

class GameOperations{
public:
    GameOperations();
    void Start();
    void move_objects();
    void handleCollisions();
    
    static bool is_game_over;
    void draw();
    void loadRect(string FilePath);
    template <typename T>
    Rectangle returnRect(shared_ptr<T> Object);
    bool getGameOver();
    bool getCollision();
    void resetCollision();


private:

    void handleCollisionPacmanGhost();
    void handleCollisionWall();
    void handleCollisionDoor();
    void handleCollisionKey();
    void handleCollisionFruit();
    void handleCollisionPellets();
    void handleCollisionStar();
    void handleCollisionSPellets();

    shared_ptr<player> playerPacman;
    vector<shared_ptr<Ghost>> Ghosts;
    vector <shared_ptr<Wall>> walls;
    vector <shared_ptr<Wall>> boundaries;
    int NumberOfBounds;
    bool gameOver;
    vector<shared_ptr<Key>> keys;
    vector<shared_ptr<Door>> doors;
    vector<shared_ptr<Fruit>> fruits;
    unique_ptr<Score> points;
    vector<shared_ptr<Star>> stars;
    bool collision;

    unique_ptr<Render> sketch;
    vector<shared_ptr<PowerPellet>> pellets;
    vector<shared_ptr<SuperPellet>> spellets;
    unique_ptr<Collisions> collide;
    int freeze;
    string input;
};

template <typename T>
Rectangle GameOperations::returnRect(shared_ptr<T> Object)
{
    return {(float)Object->get_x(), (float)Object->get_y(), (float)Object->getWidth(), (float)Object->getHeight()};
}
#endif /* CE167A85_A911_4D91_8B62_622EFB213774 */
