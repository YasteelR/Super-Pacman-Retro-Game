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