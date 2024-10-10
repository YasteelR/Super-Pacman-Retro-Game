#ifndef CE167A85_A911_4D91_8B62_622EFB213774
#define CE167A85_A911_4D91_8B62_622EFB213774

#include <string>
#include <iostream>
#include <tuple>
#include "player.h"
#include "Ghost.h"
#include "FileReader.h"
#include "Key.h"
#include "Fruit.h"
#include "Score.h"
#include "Star.h"
#include "Move.h"
#include "Render.h"
#include "Wall.h"
#include "PowerPellet.h"
#include "Collisions.h"
#include "SuperPellet.h"
#include "AssetLoader.h"

/**
 * @brief Manages game operations and logic.
 * 
 * The GameOperations class handles game state, object movement, 
 * collision detection, and rendering.
 */
class GameOperations {
public:
    GameOperations();
    
    /**
     * @brief Starts the game operations.
     */
    void Start();
    
    /**
     * @brief Moves game objects.
     */
    void move_objects();
    
    /**
     * @brief Handles collision detection and response.
     */
    void handleCollisions();
    
    static bool is_game_over; ///< Indicates if the game is over.
    
    /**
     * @brief Draws the game objects and UI.
     */
    void draw();
    
    /**
     * @brief Returns the bounding rectangle of an object.
     * 
     * @tparam T The object type.
     * @param Object The shared pointer to the object.
     * @return Rectangle The bounding rectangle.
     */
    template <typename T>
    Rectangle returnRect(shared_ptr<T> Object);
    
    /**
     * @brief Checks if the game is over.
     * 
     * @return true if the game is over, false otherwise.
     */
    bool getGameOver();
    
    /**
     * @brief Checks if a collision occurred.
     * 
     * @return true if a collision occurred, false otherwise.
     */
    bool getCollision();
    
    /**
     * @brief Resets the collision status.
     */
    void resetCollision();

private:
    void handleCollisionPacmanGhost();
    void handleCollisionWall();
    void handleCollisionDoor();
    void handleCollisionKey();
    void handleCollisionFruit();
    void handleCollisionPellets();
    void handleCollisionStar();
    void handleCollisionSPellets();
    void loadEntities(std::string FilePath);
    
    shared_ptr<player> playerPacman; ///< The player object.
    vector<shared_ptr<Ghost>> Ghosts; ///< Vector of ghost objects.
    vector <shared_ptr<Wall>> walls; ///< Vector of wall objects.
    vector <shared_ptr<Wall>> boundaries; ///< Vector of boundary objects.
    int NumberOfBounds; ///< Number of boundary objects.
    bool gameOver; ///< Indicates if the game is over.
    vector<shared_ptr<Key>> keys; ///< Vector of key objects.
    vector<shared_ptr<Door>> doors; ///< Vector of door objects.
    vector<shared_ptr<Fruit>> fruits; ///< Vector of fruit objects.
    unique_ptr<Score> points; ///< Score object.
    vector<shared_ptr<Star>> stars; ///< Vector of star objects.
    bool collision; ///< Indicates if a collision occurred.
    
    unique_ptr<Render> sketch; ///< Render object for drawing.
    vector<shared_ptr<PowerPellet>> pellets; ///< Vector of power pellet objects.
    vector<shared_ptr<SuperPellet>> spellets; ///< Vector of super pellet objects.
    unique_ptr<Collisions> collide; ///< Collision object.
    unique_ptr<AssetLoader> Generator; ///< Load in objects from txt file.

    int freeze; ///< Timer.
    string input; ///< Timing display.
};

template <typename T>
Rectangle GameOperations::returnRect(shared_ptr<T> Object) {
    return {(float)Object->get_x(), (float)Object->get_y(), (float)Object->getWidth(), (float)Object->getHeight()};
}

#endif /* CE167A85_A911_4D91_8B62_622EFB213774 */
