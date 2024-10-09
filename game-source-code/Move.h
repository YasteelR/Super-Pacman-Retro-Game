#ifndef B01A566E_8EE6_4DF0_8642_E48F2AD1AC0A
#define B01A566E_8EE6_4DF0_8642_E48F2AD1AC0A

#include "Sprite.h"

/**
 * @brief Abstract base class for movable objects.
 * 
 * The Move class provides an interface for moving and undoing moves.
 */
class Move : public Sprite {
public:
    /**
     * @brief Constructor with position parameters.
     * 
     * Initializes the move object at specified coordinates.
     * 
     * @param x The initial x-coordinate.
     * @param y The initial y-coordinate.
     */
    Move(int x, int y);
    
    /**
     * @brief Pure virtual function to move the object.
     */
    virtual void move_Obj() = 0;
    
    /**
     * @brief Pure virtual function to undo the last move.
     */
    virtual void undoLastMove() = 0;
};

#endif /* B01A566E_8EE6_4DF0_8642_E48F2AD1AC0A */
