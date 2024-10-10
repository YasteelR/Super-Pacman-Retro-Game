#ifndef D090F8A0_C96D_4D4B_A6E4_9D21C536DB0F
#define D090F8A0_C96D_4D4B_A6E4_9D21C536DB0F
#include "raylib-cpp.hpp"
#include <iostream>
#include "Sprite.h"
#include "player.h"

using namespace std;

/**
 * @brief Represents a Ghost object in the game.
 * 
 * The Ghost class handles ghost movement and behavior.
 */
class Ghost : public Sprite {
public:
    /**
     * @brief Constructor with position parameters.
     * 
     * Initializes the ghost at specified coordinates.
     * 
     * @param x The initial x-coordinate.
     * @param y The initial y-coordinate.
     */
    Ghost(int x, int y);
    
    /**
     * @brief Moves the ghost upwards.
     */
    void moveUp();
    
    /**
     * @brief Moves the ghost downwards.
     */
    void moveDown();
    
    /**
     * @brief Moves the ghost to the left.
     */
    void moveLeft();
    
    /**
     * @brief Moves the ghost to the right.
     */
    void moveRight();
    
    /**
     * @brief Moves the ghost towards the player.
     * 
     * @param pacman The shared pointer to the player object.
     */
    void move_Obj(shared_ptr<player> pacman);
    
    /**
     * @brief If power pellet is active ghosts turn blue.
     */
    void scared();

    /**
     * @brief If super pellet is active ghosts turn white.
     */
    void below();

    /**
     * @brief Undoes the last move made by the ghost.
     */
    void undoLastMove();
    
    /**
     * @brief Respawns the ghost at its original position.
     */
    void respawn();

private:
    int x_pos; ///< Current x-coordinate of the ghost.
    int y_pos; ///< Current y-coordinate of the ghost.
    string lastMove; ///< Last move made by the ghost.
    bool hor; ///< Horizontal movement flag.
    bool vert; ///< Vertical movement flag.
    int xSpawn;///< x spawn point.
    int ySpawn;///< y spawn point.
    int speed; ///< how many pixels the ghosts move.
    vector<string> pngs; ///< Different ghost image pngs.
};

#endif /* D090F8A0_C96D_4D4B_A6E4_9D21C536DB0F */
