#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED
#include "BaseObject.h"
#include "raylib-cpp.hpp"
#include <iostream>
#include "Move.h"

using namespace std;

/**
 * @brief Represents the player object in the game.
 * 
 * The player class handles player movement and state.
 */
class player : public Sprite {
public:
    /**
     * @brief Default Constructor.
     * 
     * Initializes the player.
     */
    player();

    /**
     * @brief Constructor with position parameters.
     * 
     * Initializes the player at specified coordinates.
     * 
     * @param x The initial x-coordinate.
     * @param y The initial y-coordinate.
     */
    player(int x, int y);
    
    /**
     * @brief Moves the player object.
     */
    void move_Obj();
    
    /**
     * @brief Moves the player upwards.
     */
    void moveUp();
    
    /**
     * @brief Moves the player downwards.
     */
    void moveDown();
    
    /**
     * @brief Moves the player to the left.
     */
    void moveLeft();
    
    /**
     * @brief Moves the player to the right.
     */
    void moveRight();
    
    /**
     * @brief Undoes the last player move.
     */
    void undoLastMove();
    
    /**
     * @brief Reduces player lives by one.
     */
    void loseLife();
    
    /**
     * @brief Checks if the player is dead.
     * 
     * @return true if the player is dead, false otherwise.
     */
    bool isDead();
    
    /**
     * @brief Sets the hearts displayed for lives.
     */
    void setHearts();
    
    /**
     * @brief Gets the hearts of the player.
     * 
     * @return shared_ptr<vector<shared_ptr<Sprite>>> The player's hearts.
     */
    shared_ptr<vector<shared_ptr<Sprite>>> getHearts();
    
    /**
     * @brief Sets the player's speed.
     * 
     * @param velocity The new speed for the player.
     */
    void setSpeed(int velocity);
    
    /**
     * @brief Resets movement states for the player.
     */
    void resetMovers();


private:
    vector<shared_ptr<Sprite>> hearts; ///< Vector to hold heart sprites.
    int lives; ///< Number of lives remaining.
    bool dead; ///< Indicates if the player is dead.
    string lastMove; ///< Last move made by the player.
    int vertical; ///< Vertical movement state.
    int horizontal; ///< Horizontal movement state.
    bool up; ///< Up movement flag.
    bool down; ///< Down movement flag.
    bool left; ///< Left movement flag.
    bool right; ///< Right movement flag.
    int speed; ///< Movement speed.
    int newSpeed; ///< New movement speed.
    vector<string> png; ///< filepaths to the different pngs.
};

#endif
