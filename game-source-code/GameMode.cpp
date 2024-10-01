#include "GameMode.h"
#include <iostream>
#include <raylib-cpp.hpp>
#include "player.h"


PacMan::PacMan(){    

    window = make_shared<raylib::Window>(screen_width, screen_height, "Matt-Yas_PacMan!");
    mode = Mode_select::Splash_screen;
    window->SetTargetFPS(60);
    splash = LoadTexture("../resources/pacman.png");
    splashPosition = {450,100};
    keys = LoadTexture("../resources/arrowKey.png");
    keyPosition = {1220,550};
    enter = LoadTexture("../resources/enter.png");
    enterPosition = {650, 560};
    p = LoadTexture("../resources/p.png");
    pPosition = {1330, 320};
    escape = LoadTexture("../resources/escape.png");
    escapePosition = {1330,90};
    Game_Opperations = make_unique<GameOperations>();
    cycle = 0; 
    
}

// The main function that runs all game operations 
void PacMan::run(){

    while (!window->ShouldClose()) { // Detect window close button or ESC key
    
        auto event = GetKeyPressed();
        while(event){

            //sets the mode of the game to s the correct game page
            switch(mode){

            case Mode_select::Splash_screen:
            set_splash_screen(event);
            break;

            case Mode_select::Game_screen:
            set_game_screen(event);
            break;

            case Mode_select::Pause_screen:
            set_pause_screen(event);
            break;

            case Mode_select::Game_over_screen:
            set_gameover_screen(event);
            break;
            
            }
            event = 0;
        }


        // Handles the game logic, rendering and updating data
        if (!window->ShouldClose()) {

            switch (mode){

                case Mode_select::Splash_screen:

                    BeginDrawing();
                    ClearBackground(BLACK);

                    DrawTextureEx(splash, splashPosition, 0, 1, WHITE);

                    DrawTextureEx(keys, keyPosition, 0, 1, WHITE);
                    DrawText("USE ARROW KEYS TO MOVE", 1210, 510, 25, GREEN);

                    DrawTextureEx(enter, enterPosition, 0, 1, WHITE);
                    DrawText("PRESS ENTER TO PLAY", 500, 510, 50, GREEN); 

                    DrawTextureEx(p, pPosition, 0, 1, WHITE);
                    DrawText("PRESS P TO PAUSE", 1270, 270, 25, GREEN); 

                    DrawTextureEx(escape, escapePosition, 0, 1, WHITE);
                    DrawText("PRESS ESCAPE TO EXIT", 1230, 60, 25, GREEN);

                    EndDrawing();
                break;

                case Mode_select::Game_screen:

                    Game_Opperations->move_objects(); 
                    Game_Opperations->handleCollisions();
                    Game_Opperations->draw();
                    if (Game_Opperations->getGameOver()){
                        mode=Mode_select::Game_over_screen;
                    }

                    
                break;

                case Mode_select::Pause_screen:
                    BeginDrawing();
                    ClearBackground(PINK);
                    EndDrawing();
                break;

                case Mode_select::Game_over_screen:
                    BeginDrawing();
                    DrawText("GameOver",400, 200, 80, WHITE);
                    DrawText("press esc",400, 500, 40, WHITE);  
                    ClearBackground(RED);
                    EndDrawing();
                break;
            }
        }
    }




}



void PacMan:: set_splash_screen(const int& event){

    if(IsKeyPressed(KEY_ENTER)) {
    mode=Mode_select::Game_screen;
    }
    else if(IsKeyPressed(KEY_ESCAPE)) {
        window->ShouldClose();
    }
}


void PacMan::set_game_screen(const int& event){

    if(IsKeyPressed(KEY_P)) {

    mode=Mode_select::Pause_screen;
    }

    else if(IsKeyPressed(KEY_ESCAPE)) {
        window->ShouldClose();
    }

}
void PacMan:: set_pause_screen(const int& event){


    if(IsKeyPressed(KEY_P)){
    mode=Mode_select::Game_screen;
    }

    else if(IsKeyPressed(KEY_ESCAPE)) {
        window->ShouldClose();
    }

}

void PacMan:: set_gameover_screen(const int& event)
{

    if(IsKeyPressed(KEY_ENTER)) {
    mode=Mode_select::Game_screen;
    }
    else if(IsKeyPressed(KEY_ESCAPE)) {
        window->ShouldClose();
    }
}

