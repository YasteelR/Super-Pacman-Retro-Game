#include "GameMode.h"
#include <raylib-cpp.hpp>

    auto screen_width =1600.0f;
    auto screen_height =900.0f;

PacMan::PacMan(){    

    window = make_shared<raylib::Window>(screen_width, screen_height, "Matt-Yas_PacMan!");
    mode = Mode_select::Splash_screen;
    //PacMan_Window = make_unique<GameOperation>(window);

}
void PacMan::run(){

    while (!window->ShouldClose()) { // Detect window close button or ESC key
 
        // Get the key input using a switch statement
        switch (GetKeyPressed()) {
            case KEY_ESCAPE:
                // Close
                std::cout << "close game" << std::endl;
                break;
            case KEY_ENTER:
                // Start game
                std::cout << "start game" << std::endl;
                break;
            case KEY_A:
                // Move Left
                std::cout << "Moving Left" << std::endl;
                break;
            case KEY_D:
                // Move Right
                std::cout << "Moving Right" << std::endl;
                break;
            default:
                break;
        }
    }

    if (!window->ShouldClose()) {

        switch (mode){

        case Mode_select::Splash_screen:
        splash.set_resourse_location("resources/splash_screen.png"); // can be changed in splash screen header, needed for throw

        splash.render_texture(window);
        break;

        case Mode_select::Game_screen:

        break;

        case Mode_select::Pause_screen:
        defender_game->Pause();
        break;

        case Mode_select::Game_over_screen:
        defender_game->Game_Over();
        }
  }





}