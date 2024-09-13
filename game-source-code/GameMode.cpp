#include "GameMode.h"
#include <raylib-cpp.hpp>

    int screen_width =1600;
    int screen_height =900;

PacMan::PacMan(){    

    window = make_shared<raylib::Window>(screen_width, screen_height, "Matt-Yas_PacMan!");
    mode = Mode_select::Splash_screen;
    window->SetTargetFPS(60);
    Texture2D splash = LoadTexture("superpackman.png");
    //PacMan_Window = make_unique<GameOperation>(window);

}

// The main function that runs all game operations 
void PacMan::run(){

    while (!window->ShouldClose()) { // Detect window close button or ESC key

        auto event = GetKeyPressed();
        while(!IsKeyPressed(KEY_NULL)){

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

        }


        // Handles the game logic, rendering and updating data
        if (!window->ShouldClose()) {

            switch (mode){

            case Mode_select::Splash_screen:

            BeginDrawing();
            ClearBackground(RAYWHITE);

            // Render the image (center it on screen)
            DrawTexture(splash, (screen_width - splash.width) / 2, (screen_height - splash.height) / 2, WHITE);

            // End drawing
            EndDrawing();


            break;

            case Mode_select::Game_screen:

            break;

            case Mode_select::Pause_screen:
            //PacMan_Window->Pause();
            break;

            case Mode_select::Game_over_screen:
            //PacMan_Window->Game_Over();
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

