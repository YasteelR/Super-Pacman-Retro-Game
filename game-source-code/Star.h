#ifndef BB5257F6_5AD4_4BE3_9A6C_BB94C19F6F37
#define BB5257F6_5AD4_4BE3_9A6C_BB94C19F6F37

#include "Sprite.h"
#include <cstdlib>
#include <ctime>

/**
 * @brief Represents a star with collectible fruits.
 * 
 * The Star class manages the fruit display and checks for matches.
 */
class Star : public Sprite {
public:
    Star();
    
    /**
     * @brief Sets the objects and their positions.
     */
    void setObjects();
    
    /**
     * @brief Changes the displayed fruit images.
     */
    void changeImages();
    
    /**
     * @brief Draws the companion fruits.
     */
    void DrawCompanions();
    
    /**
     * @brief Checks if the companions match.
     * 
     * @return true if they match, false otherwise.
     */
    bool CompanionsMatch();
    
    /**
     * @brief Checks if the companions match the fruit.
     * 
     * @return true if both companions are bananas, false otherwise.
     */
    bool CompanionsMatchFruit();
    
    /**
     * @brief Destroys the star and its companions.
     */
    void Destroy();
    
    /**
     * @brief Gets the companions of the star.
     * 
     * @return shared_ptr<vector<shared_ptr<Sprite>>> The companions.
     */
    shared_ptr<vector<shared_ptr<Sprite>>> getCompanions();
    
    /**
     * @brief Sets the timer for the star.
     * 
     * @param duration The duration for the timer.
     */
    void setTimer(int duration);

private:
    vector<shared_ptr<Sprite>> starFruits; ///< Companion fruits of the star.
    vector<string> fruitsFilepath; ///< File paths for fruit textures.
    int clock; ///< Timer clock.
    int timer; ///< Duration for the timer.
};

#endif /* BB5257F6_5AD4_4BE3_9A6C_BB94C19F6F37 */
