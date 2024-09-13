#ifndef AEFA9809_0E75_4129_876C_3490D6312543
#define AEFA9809_0E75_4129_876C_3490D6312543

#include <raylib-cpp.hpp>
#include <memory>

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

    void render_splash_screen();
 
    void render_game_screen();
 
    void render_pause_screen();
 
    void render_gameover_screen();


private:
    shared_ptr<raylib::Window> window;
    unique_ptr<PacMan> PacMan_Window;


}

#endif /* AEFA9809_0E75_4129_876C_3490D6312543 */


private:
    shared_ptr<sf::RenderWindow> window;
    Mode_select mode;
   // unique_ptr<GameOperations> defender_game;

};
