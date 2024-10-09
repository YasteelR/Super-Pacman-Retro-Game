#ifndef B4E447DE_F542_493E_BFDA_9697CE8ED184
#define B4E447DE_F542_493E_BFDA_9697CE8ED184

#include "Sprite.h"
#include "raylib-cpp.hpp"

/**
 * @brief Represents a Power Pellet object in the game.
 * 
 * The PowerPellet class manages power pellet behavior and state.
 */
class PowerPellet : public Sprite {
public:
    PowerPellet();
    
    /**
     * @brief Updates the duration of the power pellet.
     */
    void duration();
    
    /**
     * @brief Checks if the power pellet is active.
     * 
     * @return true if active, false otherwise.
     */
    bool activePower();
    
    /**
     * @brief Activates the power pellet.
     */
    void activate();

private:
    int active; ///< Active duration of the power pellet.
    int PelletNumber; ///< The pellet's identifier.
};

#endif /* B4E447DE_F542_493E_BFDA_9697CE8ED184 */
