#ifndef CE167A85_A911_4D91_8B62_622EFB213774
#define CE167A85_A911_4D91_8B62_622EFB213774

#include<string>
#include <iostream>
#include "player.h"

class GameOperations{
public:
    GameOperations();
    void Start();
    //void Execute_Game_Itteration();
    //void set_Game_Info(const int& score,const int& lives);
    void move_objects(GameMap& Map);
    bool checkCollisionLeft(GameMap& Map);
    static bool is_game_over;



    // put in seporate class
    void drawPlayer(GameMap& Map);  
private:
    shared_ptr<player> pacman;

    //unique_ptr<Setup> initialise_game;
    //unique_ptr<GameItteration> game_round_;
    //shared_ptr<GameData> game_data;

};
#endif /* CE167A85_A911_4D91_8B62_622EFB213774 */
