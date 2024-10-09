#ifndef DADBC4C0_964C_40F7_98D7_993A0DD45080
#define DADBC4C0_964C_40F7_98D7_993A0DD45080

#include "BaseObject.h"
#include "raylib-cpp.hpp"

/**
 * @brief Represents a Wall object in the game.
 * 
 * The Wall class manages wall dimensions and properties.
 */
class Wall : public BaseObject {
public:
    Wall();
    
    /**
     * @brief Gets the width of the wall.
     * 
     * @return int The width of the wall.
     */
    int getWidth();
    
    /**
     * @brief Gets the height of the wall.
     * 
     * @return int The height of the wall.
     */
    int getHeight();
    
    /**
     * @brief Sets the height of the wall.
     * 
     * @param height_ The new height of the wall.
     */
    void setHeight(int height_);
    
    /**
     * @brief Sets the width of the wall.
     * 
     * @param width_ The new width of the wall.
     */
    void setWidth(int width_);

private:
    int width; ///< The width of the wall.
    int height; ///< The height of the wall.
};

#endif /* DADBC4C0_964C_40F7_98D7_993A0DD45080 */
