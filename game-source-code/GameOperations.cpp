#include "GameOperations.h"

GameOperations::GameOperations(){
    playerPacman = make_shared<player>(player(1800,700));
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

bool GameOperations::checkCollisionLeft(GameMap& Map){
    
    bool collision;
    auto Xleft= playerPacman->get_x();
    auto Xright= (playerPacman->get_x()+180);
    auto Ytop= playerPacman->get_x();
    auto Ybottom= (playerPacman->get_y()+180);
    auto mapObj = Map.getMapObjects();
    auto numberRect = Map.getNoRectangles();
    int rectRight;
    int rectLeft;
    int rectTop;
    int rectBottom;

    for(int i=numberRect; i<mapObj.size(); i++)
    {   
        rectRight = mapObj[i][0] + 1100;
        rectLeft = mapObj[i][0] ;
        rectTop = mapObj[i][1]; 
        rectBottom =  mapObj[i][1] + 50;

        if ( rectRight > Xleft && Ytop < (rectTop - 50) && Ybottom > (rectBottom + 50)  ){

            collision = true;
            break;

        }else{

            collision = false;
            
        }
                      //||  mapObj[i][0] < (Xright) || mapObj[i][1] > Ybottom || (mapObj[i][1]+mapObj[i][3]) < Ytop)
        
    }    



    return collision;
}

void GameOperations::drawPlayer(GameMap& Map){

    playerPacman->draw_sprite_object_with_map(Map);

}