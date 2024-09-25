#include "GameOperations.h"

GameOperations::GameOperations(){
    playerPacman = make_shared<player>(player(800,400));
    Ghost1 = make_shared<Ghost>(Ghost(10,10));    
    movingObjects.push_back(playerPacman);
    movingObjects.push_back(Ghost1);
    Ghost1 = make_shared<Ghost>(Ghost(100,100));
    movingObjects.push_back(Ghost1);


}

void GameOperations::move_objects(GameMap& Map)
{
    for (auto& objects :movingObjects){
        objects->move_Obj();
    }
}

bool GameOperations::checkCollisionLeft(vector <shared_ptr<BaseObject>> movingObjects){
    
    bool collision;


    if (CheckCollisionRecs(movingObjects[0]->getBoundingBox() ,movingObjects[1]->getBoundingBox() )) {
        cout <<"collistion is happening "<<endl;
    }

    return collision;
}

void GameOperations::drawPlayer(GameMap& Map){
        BeginDrawing();
        ClearBackground(BLUE);
        for (auto& objects :movingObjects){
            objects->draw_sprite_object_with_map(Map);
        }
        EndDrawing();

}