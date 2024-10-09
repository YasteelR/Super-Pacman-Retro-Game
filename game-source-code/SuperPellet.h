#ifndef D3835E53_B072_4ADE_AC8E_A6F35E290691
#define D3835E53_B072_4ADE_AC8E_A6F35E290691

#include "Sprite.h"
#include "raylib-cpp.hpp"
#include <iostream>

using namespace std;

/**
 * @brief Represents a Super Pellet object in the game.
 * 
 * The SuperPellet class manages super pellet behavior and state.
 */
class SuperPellet : public Sprite {
public:
    SuperPellet();
    
    /**
     * @brief Updates the duration of the super pellet.
     */
    void duration();
    
    /**
     * @brief Checks if the super pellet is active.
     * 
     * @return true if active, false otherwise.
     */
    bool activePower();
    
    /**
     * @brief Activates the super pellet.
     */
    void activate();

private:
    int active; ///< Active duration of the super pellet.
    int PelletNumber; ///< The pellet's identifier.
};

#endif /* DADBC4C0_964C_40F7_98D7_993A0DD45080 */
