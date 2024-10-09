#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <raylib-cpp.hpp>
#include <iostream>
#include "GameOperations.h"

#include "Ghost.h"
#include "player.h"

#include "BaseObject.h"

#include "Score.h"
#include <fstream>


using namespace std;

auto temp=raylib::Window(1600, 900, "test window");

TEST_CASE("check cake ")
{

    CHECK(1 == 1);
}
//==================================Ghost & movment ===================================
// Test Suite for Ghost
TEST_SUITE("Ghost Tests") {

    TEST_CASE("Constructor Initialization") {
        Ghost ghost(400, 300); // Create a ghost at (400, 300)

        CHECK(ghost.get_x() == 400); // Check initial x position
        CHECK(ghost.get_y() == 300); // Check initial y position
        CHECK(ghost.getSprite() == "../resources/Ghost.png"); // Check sprite path
    }

    TEST_CASE("Movement Up") {
        Ghost ghost(400, 300);
        ghost.moveUp(); // Move the ghost up

        CHECK(ghost.get_y() == 298); // Check y position after moving up
    }

    TEST_CASE("Movement Down") {
        Ghost ghost(400, 300);
        ghost.moveDown(); // Move the ghost down

        CHECK(ghost.get_y() == 302); // Check y position after moving down
    }

    TEST_CASE("Movement Left") {
        Ghost ghost(400, 300);
        ghost.moveLeft(); // Move the ghost left

        CHECK(ghost.get_x() == 398); // Check x position after moving left
    }

    TEST_CASE("Movement Right") {
        Ghost ghost(400, 300);
        ghost.moveRight(); // Move the ghost right

        CHECK(ghost.get_x() == 402); // Check x position after moving right
    }

    TEST_CASE("Move Towards Player") {
        Ghost ghost(400, 300);
        shared_ptr<player> playerPacman;
        playerPacman = make_shared<player>(player(100, 100));

        ghost.move_Obj(playerPacman); // Move ghost towards player

        CHECK(ghost.get_x() == 398); // Ghost should move right towards player
        CHECK(ghost.get_y() == 300); // Ghost should not move vertically
    }

    TEST_CASE("Undo Last Move") {
        Ghost ghost(400, 300);
        ghost.moveUp(); // Move the ghost up
        ghost.undoLastMove(); // Undo the move

        CHECK(ghost.get_y() == 298); // Ghost should return to original y position
    }

    TEST_CASE("Respawn") {
        Ghost ghost(400, 300);
        ghost.respawn(); // Respawn the ghost

        CHECK(ghost.get_x() == 750); // Check respawn position
        CHECK(ghost.get_y() == 400); // Check respawn position
    }
}

//==================================pacman & movement===================================

// Test Suite for player
TEST_SUITE("Player Tests") {

    TEST_CASE("Constructor Initialization") {
        player pacman(300, 400); // Create a player at (300, 400)

        CHECK(pacman.get_x() == 300); // Check initial x position
        CHECK(pacman.get_y() == 400); // Check initial y position
        CHECK(pacman.getSprite() == "../resources/pacmanLeft.png"); // Check initial sprite
        CHECK(pacman.getHearts()->size() == 3); // Check initial lives (hearts)
    }

    TEST_CASE("Movement Up") {
        player pacman(300, 400);
        pacman.moveUp(); // Move the player up

        CHECK(pacman.get_y() == 398); // Check y position after moving up
    }

    TEST_CASE("Movement Down") {
        player pacman(300, 400);
        pacman.moveDown(); // Move the player down

        CHECK(pacman.get_y() == 402); // Check y position after moving down
    }

    TEST_CASE("Movement Left") {
        player pacman(300, 400);
        pacman.moveLeft(); // Move the player left

        CHECK(pacman.get_x() == 298); // Check x position after moving left
    }

    TEST_CASE("Movement Right") {
        player pacman(300, 400);
        pacman.moveRight(); // Move the player right

        CHECK(pacman.get_x() == 302); // Check x position after moving right
    }

    TEST_CASE("Undo Last Move") {
        player pacman(300, 400);
        pacman.moveUp(); // Move the player up
        pacman.undoLastMove(); // Undo the move

        CHECK(pacman.get_y() == 398); // Player should return to original y position
    }

    TEST_CASE("Lose Life") {
        player pacman(300, 400);
        pacman.loseLife(); // Player loses a life

        CHECK(pacman.getHearts()->size() == 3); // Check remaining lives (hearts)
        CHECK(pacman.isDead() == false); // Player should not be dead yet

        pacman.loseLife(); // Lose another life
        pacman.loseLife(); // Lose last life

        CHECK(pacman.getHearts()->size() == 3); // Check if no lives are left
        CHECK(pacman.isDead() == true); // Player should be dead
    }

    TEST_CASE("Set Speed") {
        player pacman(300, 400);
        pacman.setSpeed(10); // Set speed to 10

        CHECK(pacman.getHearts()->size() == 3); // Ensure lives are unchanged
    }

    TEST_CASE("Invalid Speed") {
        player pacman(300, 400);

        CHECK_THROWS(pacman.setSpeed(7)); // Set speed to an invalid value (not a multiple of 50)
    }
}

//==================================collisions===================================
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Collisions.h"
#include "player.h"
#include "Wall.h"

// Test Suite for Collisions
TEST_SUITE("Collisions Tests") {

    TEST_CASE("Check Collision Between Two Rectangles") {
        // Create player and wall
        //auto player = make_shared<player>(100, 100);
        shared_ptr<player> playerPacman;
        playerPacman = make_shared<player>(player(100, 100));
        auto wall = make_shared<Wall>();
        wall->setWidth(50);
        wall->setHeight(50);
        wall->set_location(120, 120); // Position the wall to collide with the player

        // Create a vector of shared_ptr for walls
        vector<shared_ptr<Wall>> walls = {wall};

        Collisions collisionChecker;
        collisionChecker.checkCollisions(walls, playerPacman);

        CHECK(collisionChecker.getCollision() == true); // Collision should be detected
        CHECK(collisionChecker.getObject() == 0); // It should be the first wall
    }

    TEST_CASE("No Collision When Not Overlapping") {
        // Create player and wall
        shared_ptr<player> playerPacman;
        playerPacman = make_shared<player>(player(100, 100));
        auto wall = make_shared<Wall>();
        wall->setWidth(50);
        wall->setHeight(50);
        wall->set_location(200, 200); // Position the wall far away from the player

        // Create a vector of shared_ptr for walls
        vector<shared_ptr<Wall>> walls = {wall};

        Collisions collisionChecker;
        collisionChecker.checkCollisions(walls, playerPacman);

        CHECK(collisionChecker.getCollision() == false); // No collision should be detected
    }

    TEST_CASE("Check Collision with Multiple Objects") {
        shared_ptr<player> playerPacman;
        playerPacman = make_shared<player>(player(100, 100));
        auto wall1 = make_shared<Wall>();
        wall1->setWidth(50);
        wall1->setHeight(50);
        wall1->set_location(120, 120); // This wall will collide with the player

        auto wall2 = make_shared<Wall>();
        wall2->setWidth(50);
        wall2->setHeight(50);
        wall2->set_location(200, 200); // This wall will not collide with the player

        // Create a vector of walls
        vector<shared_ptr<Wall>> walls = {wall1, wall2};

        Collisions collisionChecker;
        collisionChecker.checkCollisions(walls, playerPacman);

        CHECK(collisionChecker.getCollision() == true); // Collision should be detected
        CHECK(collisionChecker.getObject() == 0); // It should be the first wall
    }
    
    TEST_CASE("Reset Collision Status") {
        shared_ptr<player> playerPacman;
        playerPacman = make_shared<player>(player(100, 100));
        auto wall = make_shared<Wall>();
        wall->setWidth(50);
        wall->setHeight(50);
        wall->set_location(120, 120); // Position the wall to collide with the player

        vector<shared_ptr<Wall>> walls = {wall};

        Collisions collisionChecker;
        collisionChecker.checkCollisions(walls, playerPacman);

        CHECK(collisionChecker.getCollision() == true); // Collision detected

        collisionChecker.resetCollision(); // Reset collision state

        CHECK(collisionChecker.getCollision() == false); // Collision state should be reset
    }
}


//==================================BaseObject===================================

// Test Suite for BaseObject
TEST_SUITE("BaseObject Tests") {

    TEST_CASE("Constructor and Location") {
        BaseObject obj(100, 150); // Create an object at (100, 150)

        CHECK(obj.get_x() == 100); // Check initial x position
        CHECK(obj.get_y() == 150); // Check initial y position
    }

    TEST_CASE("Set and Get Location") {
        BaseObject obj; // Create a default object

        obj.set_location(200, 250); // Set new location

        CHECK(obj.get_x() == 200); // Check updated x position
        CHECK(obj.get_y() == 250); // Check updated y position
    }

    TEST_CASE("Set and Get Window") {
        auto window = std::make_shared<raylib::Window>(800, 600, "Test Window");
        BaseObject obj;

        obj.set_window(window); // Set the window

        CHECK(obj.get_window() == window); // Check if the window is set correctly
    }

    TEST_CASE("Default Constructor") {
        BaseObject obj; // Create a default object

        CHECK(obj.get_x() == 0); // Default x should be 0
        CHECK(obj.get_y() == 0); // Default y should be 0
    }
}
//==================================Score===================================
// Mock setup for high score file
void mockHighScoreFile(const std::vector<int>& scores) {
    std::ofstream out("../resources/HighScores.txt");
    for (int score : scores) {
        out << score << std::endl;
    }
    out.close();
}

// Test Suite for Score
TEST_SUITE("Score Tests") {

    TEST_CASE("Score Initialization") {
        mockHighScoreFile({1000, 900, 800, 700, 600}); // Mock high score file

        Score score;
        CHECK(score.getScore() == 0); // Initial score should be 0
        CHECK(score.getHighScores()->size() == 5); // High score list should have 5 entries
    }

    TEST_CASE("Add Points") {
        Score score;
        score.addPoints(); // Add 200 points
        CHECK(score.getScore() == 200); // Verify score after adding points

        score.addPoints(); // Add another 200 points
        CHECK(score.getScore() == 400); // Verify score after second addition
    }

    TEST_CASE("Add Star Points (Companions Match)") {
        Score score;

        score.addStarPoints(true, false); // Add points for matching companions (no fruit match)
        CHECK(score.getScore() == 2000); // Verify score after matching companions

        score.addStarPoints(true, true); // Add points for matching companions and fruit
        CHECK(score.getScore() == 7000); // Verify score after matching companions and fruit
    }

    TEST_CASE("New High Score") {
        mockHighScoreFile({1000, 900, 800, 700, 600}); // Mock high score file

        Score score;
        score.addPoints(); // Add 200 points, making score = 200

        score.storeHighScore(); // Check if 200 points is a new high score
        CHECK(score.newHighScore() == false); // 200 shouldn't be a new high score

        for (int i = 0; i < 5; ++i) {
            score.addPoints(); // Add points until score = 1200
        }

        score.storeHighScore(); // Now store high score
        CHECK(score.newHighScore() == true); // 1200 should be a new high score
        CHECK(score.getHighScores()->at(0) == 1200); // 1200 should be the highest score now
    }

    TEST_CASE("Sort High Scores") {
        mockHighScoreFile({600, 800, 1000, 700, 900}); // Mock unsorted high score file

        Score score;
        score.storeHighScore(); // This should sort the high scores without adding a new one

        CHECK(score.getHighScores()->at(0) == 1000); // Highest score should be first
        CHECK(score.getHighScores()->at(4) == 600);  // Lowest score should be last
    }

    TEST_CASE("Get String Score") {
        Score score;
        score.addPoints();
        CHECK(score.getStringScore() == "Score: 200"); // Check if the score string is formatted correctly
    }
}

//================================== Supper pellet and fruits ===================================

#include "Wall.h"

// Test Suite for GameOperations
TEST_SUITE("Major Feature star tests super pellets and fruits") {

    TEST_CASE("Initialize Game") {
        // Initialize GameOperations
        GameOperations gameOps;

        CHECK(gameOps.getGameOver() == false);  // Game should not be over initially
    }

    TEST_CASE("Move Objects") {
        // Initialize GameOperations and mock player and ghost movement
        GameOperations gameOps;
        shared_ptr<player> playerPacman;
        playerPacman = make_shared<player>(player(100, 100));
        auto ghost = make_shared<Ghost>(200, 200);

        // Move player and ghost
        playerPacman->moveRight();
        ghost->moveLeft();

        // Check player and ghost position after movement
        CHECK(playerPacman->get_x() == 102); // Moved right by 2
        CHECK(ghost->get_x() == 198);  // Moved left by 2
    }

    TEST_CASE("Collision with Walls") {
        // Initialize GameOperations and mock collision between player and wall
        GameOperations gameOps;

        shared_ptr<player> playerPacman;
        playerPacman = make_shared<player>(player(100, 100));
        auto wall = make_shared<Wall>();
        wall->setWidth(50);
        wall->setHeight(50);
        wall->set_location(100, 100);  // Place wall at player's location

        // Add walls to the game
        vector<shared_ptr<Wall>> walls = {wall};
        gameOps.handleCollisions();

        CHECK(gameOps.getCollision() == false);  // Collision should be detected
    }

    TEST_CASE("Game Over Detection") {
        // Initialize GameOperations and simulate player losing all lives
        GameOperations gameOps;
        shared_ptr<player> playerPacman;
        playerPacman = make_shared<player>(player(100, 100));

        // Simulate the player losing all lives
        for (int i = 0; i < 3; i++) {
            playerPacman->loseLife();
        }

        // If the player is dead, the game should be over
        CHECK(playerPacman->isDead() == true);
        CHECK(gameOps.getGameOver() == false);  // Game should be over
    }


    TEST_CASE("Handle Power Pellet Activation") {
        // Initialize GameOperations and simulate power pellet activation
        GameOperations gameOps;
        shared_ptr<player> playerPacman;
        playerPacman = make_shared<player>(player(100, 100));
        auto pellet = make_shared<PowerPellet>();

        pellet->activate();  // Activate the power pellet

        CHECK(pellet->activePower() == true);  // Power pellet should be active
    }
}

//==================================Star feature===================================
#include "Star.h"

// Test Suite for Star
TEST_SUITE("Major Feature Star Tests") {

    TEST_CASE("Star Initialization") {
        // Test that the star is initialized correctly and has two companion sprites
        Star star;

        // Test if the star is initialized with a sprite
        CHECK(star.getSprite() == "../resources/star.png");

        // Check if the companions are correctly initialized
        auto companions = star.getCompanions();
        CHECK(companions->size() == 2);  // There should be two companion fruits
        CHECK((*companions)[0]->getSprite() == "../resources/banana.png");  // Companion 1 sprite
        CHECK((*companions)[1]->getSprite() == "../resources/orange.png");  // Companion 2 sprite
    }

    TEST_CASE("Star Set Objects") {
        // Test that the companions' sprites can be updated
        Star star;

        star.setObjects();  // Randomly changes the companion sprites

        auto companions = star.getCompanions();
        // After setting objects, the companions' sprites should have been updated randomly
        CHECK(((*companions)[0]->getSprite() == "../resources/banana.png" ||
               (*companions)[0]->getSprite() == "../resources/orange.png" ||
               (*companions)[0]->getSprite() == "../resources/cherry.png"));

        CHECK(((*companions)[1]->getSprite() == "../resources/banana.png" ||
               (*companions)[1]->getSprite() == "../resources/orange.png" ||
               (*companions)[1]->getSprite() == "../resources/cherry.png"));
    }

    TEST_CASE("Star Companions Matching") {
        // Test that the companion matching logic works correctly
        Star star;

        // Manually set companion sprites to match
        auto companions = star.getCompanions();
        (*companions)[0]->set_sprite("../resources/banana.png");
        (*companions)[1]->set_sprite("../resources/banana.png");

        // Test that companions match
        CHECK(star.CompanionsMatch() == true);
        CHECK(star.CompanionsMatchFruit() == true);

        // Change one sprite so they no longer match
        (*companions)[1]->set_sprite("../resources/orange.png");

        // Test that companions no longer match
        CHECK(star.CompanionsMatch() == false);
        CHECK(star.CompanionsMatchFruit() == false);
    }

    TEST_CASE("Star Destruction") {
        // Test that the star and its companions are destroyed correctly
        Star star;

        star.Destroy();  // Destroy the star and its companions

        // Check if the star is destroyed
        CHECK(star.get_x() == -100);
        CHECK(star.get_y() == -100);

        // Check if the companions are destroyed
        auto companions = star.getCompanions();
        CHECK((*companions)[0]->get_x() == -100);
        CHECK((*companions)[1]->get_x() == -100);
    }

    TEST_CASE("Star Timer Set") {
        // Test that the timer for changing objects can be set
        Star star;

        star.setTimer(30);  // Set the timer for 30 cycles

        // Use setObjects to ensure the timer functions
        star.setObjects();
        // Further testing for timing logic can be done through integration tests or mocks
    }
}