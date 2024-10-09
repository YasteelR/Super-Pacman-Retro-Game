#include "Ghost.h"

Ghost::Ghost(int x, int y)
: Sprite(x,y)
{
    set_sprite("../resources/ghost.png");
    vert = true;
    hor = true;
    xSpawn=x;
    ySpawn=y;
    speed=2;
}

void Ghost::moveUp(){
    set_location(get_x(), get_y() - speed);

}

void Ghost::moveDown() {
    set_location(get_x(), get_y() + speed);

}

void Ghost::moveLeft() {
    set_location(get_x() - speed, get_y() );

}

void Ghost::moveRight() {
    set_location(get_x() + speed, get_y() );
}

void Ghost::move_Obj(shared_ptr<player> pacman){
    auto playerX = pacman->get_x(); // Get the player's current x-coordinate.
    auto playerY = pacman->get_y(); // Get the player's current y-coordinate.

    auto xDistance = playerX - get_x(); // Calculate the distance in the x direction.
    auto yDistance = playerY - get_y(); // Calculate the distance in the y direction.
    
    if (xDistance > 0 && hor) { // Move right if the player is to the right and horizontal movement is allowed.
        moveRight();
        lastMove = "right"; // Update the last move.
        return;
    }
    if (xDistance < 0 && hor) { // Move left if the player is to the left and horizontal movement is allowed.
        moveLeft();
        lastMove = "left"; // Update the last move.
        return;
    }
    if (yDistance < 0 && vert) { // Move up if the player is above and vertical movement is allowed.
        moveUp();
        lastMove = "up"; // Update the last move.
        return;
    }
    if (yDistance > 0 && vert) { // Move down if the player is below and vertical movement is allowed.
        moveDown();
        lastMove = "down"; // Update the last move.
        return;
    }
    
    // Reset movement flags if no movement occurred.
    vert = true;
    hor = true;
}

void Ghost::undoLastMove() {
    // Undo the last move based on the stored direction.
    if (lastMove == "up") {
        moveDown(); // Move down to undo the upward movement.
        vert = false; // Prevent further vertical movement.
    }
    else if (lastMove == "down") {
        moveUp(); // Move up to undo the downward movement.
        vert = false; // Prevent further vertical movement.
    }
    else if (lastMove == "left") {
        moveRight(); // Move right to undo the leftward movement.
        hor = false; // Prevent further horizontal movement.
    }
    else if (lastMove == "right") {
        moveLeft(); // Move left to undo the rightward movement.
        hor = false; // Prevent further horizontal movement.
    }
    else {
        std::cout << "Invalid move!" << std::endl; // Handle unexpected state.
    }
}

void Ghost::respawn()
{
    set_location(xSpawn, ySpawn); // Reset the ghost's position to its spawn point.
}