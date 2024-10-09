#ifndef A4EC8B3D_2578_488A_8DDC_D51A5CCCD2FC
#define A4EC8B3D_2578_488A_8DDC_D51A5CCCD2FC

#include "Sprite.h"

/**
 * @brief Represents a Fruit object in the game.
 * 
 * The Fruit class manages fruit objects, including their state and actions.
 */
class Fruit : public Sprite {
public:
    Fruit();
    
    /**
     * @brief Gets the number of fruits.
     * 
     * @return int The current number of fruits.
     */
    int getFruitNum();
    
    /**
     * @brief Handles the event of a fruit being eaten.
     */
    static void eatenFruit();
    
    /**
     * @brief Destroys the fruit by resetting its position.
     */
    void Destroy();
    
    /**
     * @brief Resets the fruit count.
     */
    static void reset();

private:
    static int NumOfFruit; ///< The total number of fruits.
};

#endif /* A4EC8B3D_2578_488A_8DDC_D51A5CCCD2FC */
