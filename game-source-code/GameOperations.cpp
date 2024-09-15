#include "GameOperations.h"

GameOperations::GameOperations(){
    pacman = make_shared<player>(player(1800,700));


}

void GameOperations::move_objects(){

    if (IsKeyPressed(KEY_W) || IsKeyPressed(KEY_S) || IsKeyPressed(KEY_A) || IsKeyPressed(KEY_D)) {
            // Get the key input using a switch statement
            switch (GetKeyPressed()) {
                case KEY_W:
                    // Move Up
                    pacman->moveUp();
                    break;
                case KEY_S:
                    // Move Down
                    pacman->moveDown();
                    break;
                case KEY_A:
                    // Move Left
                    pacman->moveLeft();
                    break;
                case KEY_D:
                    // Move Right
                    pacman->moveRight();
                    break;
                default:
                    break;
            }

    }
    
    if(IsKeyDown(KEY_UP)) {
        pacman->moveUp();
    }
    else if(IsKeyDown(KEY_DOWN)) {
        pacman->moveDown();
    }
    if(IsKeyDown(KEY_RIGHT)) {
        pacman->moveRight();
    }
    else if(IsKeyDown(KEY_LEFT)) {
        pacman->moveLeft();
    }
}


void GameOperations::drawPlayer(GameMap& Map){

    //BeginDrawing();

    
    //ClearBackground(BLUE);
    //pacman->draw_sprite_object();
    pacman->draw_sprite_object_with_map(Map);

    //PacMan_Window->drawPlayer();
    // End drawing
    //EndDrawing();
    
    cout<<"drawing pacman++++++++++++++"<<endl;

}