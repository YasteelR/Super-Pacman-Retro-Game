#include "GameMode.h"
#include <iostream>
#include <raylib-cpp.hpp>
#include "player.h"


PacMan::PacMan(){    

    window = make_shared<raylib::Window>(screen_width, screen_height, "Matt-Yas_PacMan!");
    mode = Mode_select::Splash_screen;
    window->SetTargetFPS(60);
    splash = LoadTexture("../resources/pacman.png");
    cout<< "Constructed "<<endl;
    PacMan_Window = make_unique<GameOperations>();    
    
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
            cout << "event wile loop=============="<<endl;
            event = 0;
        }


        // Handles the game logic, rendering and updating data
        if (!window->ShouldClose()) {

            switch (mode){

            case Mode_select::Splash_screen:

                BeginDrawing();
                ClearBackground(GREEN);
                //splash = LoadTexture("pacman.png");

                // Render the image (center it on screen)
                DrawTextureEx(splash, ZeroZero,0, 2.35, WHITE); 
                cout << "rnederrrr /////////////////"<<endl;

                // End drawing
                EndDrawing();


            break;

            case Mode_select::Game_screen:

                PacMan_Window->move_objects();

                
                // BeginDrawing();

                
                // ClearBackground(BLUE);
                //Map.DrawMap();

                PacMan_Window->drawPlayer();
                // // End drawing
                // EndDrawing();






            break;

            case Mode_select::Pause_screen:
                BeginDrawing();
                ClearBackground(PINK);
                // End drawing
                EndDrawing();
            break;

            case Mode_select::Game_over_screen:
                BeginDrawing();
                ClearBackground(RED);
                // End drawing
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

