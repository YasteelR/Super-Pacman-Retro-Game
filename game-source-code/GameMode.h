#ifndef AEFA9809_0E75_4129_876C_3490D6312543
#define AEFA9809_0E75_4129_876C_3490D6312543

#include <raylib-cpp.hpp>
#include <memory>
#include "GameOperations.h"

using namespace std;

enum Mode_select{
    Splash_screen,
    Game_screen,
    Pause_screen,
    Game_over_screen
};


class PacMan {
public:

    PacMan();

    void run();

    void set_splash_screen(const int& event);
 
    void set_game_screen(const int& event);
 
    void set_pause_screen(const int& event);
 
    void set_gameover_screen(const int& event);


private:
    shared_ptr<raylib::Window> window;
    unique_ptr<GameOperations> Game_Opperations;
    Mode_select mode;
    raylib::Texture2D splash;
    Vector2 ZeroZero = {0,0};
    const int screen_width =1600;
    const int screen_height =900;
};

#endif /* AEFA9809_0E75_4129_876C_3490D6312543 */

/*
private:

    shared_ptr<sf::RenderWindow> window;
    Mode_select mode;
   // unique_ptr<GameOperations> defender_game;

};
*/
