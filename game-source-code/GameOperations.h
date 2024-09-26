#ifndef CE167A85_A911_4D91_8B62_622EFB213774
#define CE167A85_A911_4D91_8B62_622EFB213774

#include <string>
#include <iostream>
#include "player.h"
#include "Ghost.h"
#include "GameData.h"
#include "FileReader.h"
#include "Key.h"
#include "Fruit.h"
#include "Score.h"
#include "Star.h"

class GameOperations{
public:
    GameOperations();
    void Start();
    void move_objects();
    bool checkCollisionPacmanGhost();
    void checkCollisionWall();
    void checkCollisionDoor();
    void checkCollisionKey();
    void checkCollisionFruit();
    void checkCollisionPellets();
    static bool is_game_over;
    void draw();
    void loadRect(string FilePath);
    Rectangle returnRect(int& i, vector<int>& vector);
    bool getGameOver();
    void checkCollisionStar();

private:


    shared_ptr<player> playerPacman;
    shared_ptr<Ghost> Ghost1;
    vector <shared_ptr<BaseObject>> movingObjects;
    vector<int> WallCoordinates;
    int NumberOfWalls;
    vector<int> boundaryCoordinates;
    int NumberOfBounds;
    vector<int> pellets;
    int NumberOfPellets;
    bool gameOver;
    vector<shared_ptr<Key>> keys;
    int NumberOfKeys;
    vector<int> doors;
    int NumberOfDoors;
    vector<shared_ptr<Fruit>> fruits;
    int NumberOfFruits;
    Score points;
    vector<shared_ptr<Star>> stars;
    int NumberOfStars;

};
#endif /* CE167A85_A911_4D91_8B62_622EFB213774 */
