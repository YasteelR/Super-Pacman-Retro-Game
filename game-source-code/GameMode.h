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

/**
 * @brief Manages the game state and transitions between screens.
 * 
 * The PacMan class handles the game loop, screen management,
 * and user input.
 */
class PacMan {
public:
    PacMan();
    
    /**
     * @brief Runs the main game loop.
     */
    void run();
    
    /**
     * @brief Sets the splash screen state.
     * 
     * @param event The key event.
     */
    void set_splash_screen(const int& event);
    
    /**
     * @brief Sets the game screen state.
     * 
     * @param event The key event.
     */
    void set_game_screen(const int& event);
    
    /**
     * @brief Sets the pause screen state.
     * 
     * @param event The key event.
     */
    void set_pause_screen(const int& event);
    
    /**
     * @brief Sets the game over screen state.
     * 
     * @param event The key event.
     */
    void set_gameover_screen(const int& event);

private:
    shared_ptr<raylib::Window> window; ///< The game window.
    unique_ptr<GameOperations> Game_Opperations; ///< Game operations handler.
    Mode_select mode; ///< Current game mode.
    raylib::Texture2D splash; ///< Texture for the splash screen.
    raylib::Texture2D keys; ///< Texture for key controls.
    raylib::Texture2D enter; ///< Texture for the enter key.
    raylib::Texture2D p; ///< Texture for the pause key.
    raylib::Texture2D escape; ///< Texture for the escape key.
    Vector2 splashPosition; ///< Position for the splash screen texture.
    Vector2 keyPosition; ///< Position for the key controls texture.
    Vector2 enterPosition; ///< Position for the enter key texture.
    Vector2 pPosition; ///< Position for the pause key texture.
    Vector2 escapePosition; ///< Position for the escape key texture.
    const int screen_width = 1600; ///< Width of the window.
    const int screen_height = 900; ///< Height of the window.
    int cycle; ///< Game cycle counter.
};

#endif /* AEFA9809_0E75_4129_876C_3490D6312543 */
