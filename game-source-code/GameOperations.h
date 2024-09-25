#ifndef CE167A85_A911_4D91_8B62_622EFB213774
#define CE167A85_A911_4D91_8B62_622EFB213774

#include<string>
#include <iostream>
#include "player.h"
#include "Ghost.h"

class GameOperations{
public:
    GameOperations();
    void Start();
    void move_objects(GameMap& Map);
    bool checkCollisionLeft(vector <shared_ptr<BaseObject>> movingObjects);
    static bool is_game_over;
    void drawPlayer(GameMap& Map);

private:


    shared_ptr<player> playerPacman;
    shared_ptr<Ghost> Ghost1;
    vector <shared_ptr<BaseObject>> movingObjects;



};
#endif /* CE167A85_A911_4D91_8B62_622EFB213774 */
