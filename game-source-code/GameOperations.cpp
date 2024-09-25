#include "GameOperations.h"

GameOperations::GameOperations(){
    playerPacman = make_shared<player>(player(800,400));
    Ghost1 = make_shared<Ghost>(Ghost(200,200));    
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

bool GameOperations::checkCollision(){
    
    bool collision;
    for (auto i = 1; i < 3; i++ ){
        if (CheckCollisionRecs(movingObjects[0]->getBoundingBox() ,movingObjects[i]->getBoundingBox() )) {
            collision = true;
            cout <<"collistion is happening "<<endl;
            cout <<"player x:"<<movingObjects[0]->get_x()<<"player y:"<<movingObjects[0]->get_y()<<endl;
            cout <<"ghost x:"<<movingObjects[i]->get_x()<<"ghost y:"<<movingObjects[i]->get_y()<<endl;
        }
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