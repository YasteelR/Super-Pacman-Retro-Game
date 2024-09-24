#ifndef CE167A85_A911_4D91_8B62_622EFB213774
#define CE167A85_A911_4D91_8B62_622EFB213774

#include<string>
#include <iostream>
#include "player.h"

class GameOperations{
public:
    GameOperations();
    void Start();
    void move_objects(GameMap& Map);
    bool checkCollisionLeft(GameMap& Map);
    static bool is_game_over;
    void drawPlayer(GameMap& Map);

private:


    shared_ptr<player> playerPacman;



};
#endif /* CE167A85_A911_4D91_8B62_622EFB213774 */
