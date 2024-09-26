#ifndef CE167A85_A911_4D91_8B62_622EFB213774
#define CE167A85_A911_4D91_8B62_622EFB213774

#include <string>
#include <iostream>
#include "player.h"
#include "Ghost.h"
#include "GameData.h"
#include "FileReader.h"
#include "Key.h"

class GameOperations{
public:
    GameOperations();
    void Start();
    void move_objects();
    bool checkCollisionPacmanGhost();
    void checkCollisionWall();
    void checkCollisionPellets();
    static bool is_game_over;
    void draw();
    void loadRect(string FilePath);
    Rectangle returnRect(int& i, vector<int>& vector);
    bool getGameOver();

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
    vector<shared_ptr<Door>> doors;
    int NumberOfDoors;

};
#endif /* CE167A85_A911_4D91_8B62_622EFB213774 */
