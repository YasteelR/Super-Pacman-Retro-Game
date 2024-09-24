#include "GameOperations.h"

GameOperations::GameOperations(){
    playerPacman = make_shared<player>(player(1800,700));
    playerPacman->set_sprite("resources/pacmanLeft.png");

}

void GameOperations::move_objects(GameMap& Map){

    if (IsKeyPressed(KEY_W) || IsKeyPressed(KEY_S) || IsKeyPressed(KEY_A) || IsKeyPressed(KEY_D)) {
            // Get the key input using a switch statement
            switch (GetKeyPressed()) {
                case KEY_W:
                    // Move Up
                    playerPacman->moveUp();
                    break;
                case KEY_S:
                    // Move Down
                    playerPacman->moveDown();
                    break;
                case KEY_A:
                    // Move Left
                    playerPacman->moveLeft();
                    break;
                case KEY_D:
                    // Move Right
                    playerPacman->moveRight();
                    break;
                default:
                    break;
            }

    }
    //bool collision = checkCollisionLeft(Map);
    //if (!collision){
        if(IsKeyDown(KEY_UP)) {
            playerPacman->moveUp();
        }
        else if(IsKeyDown(KEY_DOWN)) {
            playerPacman->moveDown();
        }
        if(IsKeyDown(KEY_RIGHT)) {
            playerPacman->moveRight();
        }
        else if(IsKeyDown(KEY_LEFT)) {
            playerPacman->moveLeft();
        }
    //}
    //else{
    //    playerPacman->moveRight();
    //}
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
        //cout <<i<<endl;
        //cout << "  X1=" << rectLeft <<"  Y1=" <<rectTop<<"  X2=" <<rectRight <<"  Y2="<<rectBottom<<endl;
        //cout << "  X1=" << Xleft <<"  Y1=" <<Ytop<<"  X2=" <<Xright <<"  Y2="<<Ybottom<<endl;

        if ( rectRight > Xleft && Ytop < (rectTop - 50) && Ybottom > (rectBottom + 50)  ){

            collision = true;
            break;

        }else{

            collision = false;
            
        }



        // if(    ((mapObj[i][0]+mapObj[i][2]) > Xleft  && mapObj[i][0] < Xleft &&   (mapObj[i][1]+mapObj[i][3]) > Ytop &&  mapObj[i][1] > Ytop ) ){

        //     collision = true;
        // }
        // else {
        //     collision = false;
        // }

        //mapObj[i][0], mapObj[i][1], mapObj[i][2], mapObj[i][3];      &&  mapObj[i][1] > Ytop 
        
        
                      //||  mapObj[i][0] < (Xright) || mapObj[i][1] > Ybottom || (mapObj[i][1]+mapObj[i][3]) < Ytop)
        
    }    



    return collision;
}

void GameOperations::drawPlayer(GameMap& Map){

    //BeginDrawing();

    
    //ClearBackground(BLUE);
    //playerPacman->draw_sprite_object();
    playerPacman->draw_sprite_object_with_map(Map);

    //playerPacman_Window->drawPlayer();
    // End drawing
    //EndDrawing();
    
    //cout<<"drawing pacman++++++++++++++"<<endl;

}