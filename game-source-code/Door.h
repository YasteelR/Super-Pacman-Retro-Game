#ifndef C98DA9BF_020E_42CF_BEB5_1BAAFD9D9AEC
#define C98DA9BF_020E_42CF_BEB5_1BAAFD9D9AEC

#include "BaseObject.h"
#include "raylib-cpp.hpp"
#include <iostream>

using namespace std;

/**
 * @brief Represents a Door object in the game.
 * 
 * The Door class provides functionality for door objects,
 * including getting and setting dimensions.
 */
class Door : public BaseObject {
public:
    Door();
    /**
     * @brief Gets the width of the door.
     * 
     * @return int The width of the door.
     */
    int getWidth();
    
    /**
     * @brief Gets the height of the door.
     * 
     * @return int The height of the door.
     */
    int getHeight();
    
    /**
     * @brief Sets the width of the door.
     * 
     * @param width_ The new width of the door.
     */
    void setWidth(int width_);
    
    /**
     * @brief Sets the height of the door.
     * 
     * @param height_ The new height of the door.
     */
    void setHeight(int height_);
    
    /**
     * @brief Destroys the door by resetting its position and dimensions.
     */
    void destroy();

private:
    int width;  ///< The width of the door.
    int height; ///< The height of the door.
};

#endif /* C98DA9BF_020E_42CF_BEB5_1BAAFD9D9AEC */
