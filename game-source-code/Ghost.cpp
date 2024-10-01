#include "Ghost.h"

Ghost::Ghost(int x, int y)
: Sprite(x,y)
{
    set_sprite("../resources/Ghost.png");
}

void Ghost::moveUp(){
    set_location(get_x(), get_y() - 2);

}

void Ghost::moveDown() {
    set_location(get_x(), get_y() + 2);

}

void Ghost::moveLeft() {
    set_location(get_x() - 2, get_y() );

}

void Ghost::moveRight() {
    set_location(get_x() + 2, get_y() );
}

void Ghost::move_Obj(){
    auto playerX = getPlayerX();
    auto playerY = getPlayerY();

    auto xDistance = playerX - get_x();
    auto yDistance = playerY - get_y();
    if (xDistance > 0){
        moveRight();
        lastMove = "right";
        return;
    }else if (xDistance < 0){
        moveLeft();
        lastMove = "left";
        return;
    }else if (yDistance < 0){
        moveUp();
        lastMove = "up";
        return;
    }else if ( yDistance > 0){
        moveDown();
        lastMove = "down";
        return;
    }

};

void Ghost::undoLastMove() {
    if (lastMove == "up") {
        moveDown();
    }
    else if (lastMove == "down") {
        moveUp();
    }
    else if (lastMove == "left") {
       moveRight();
    }
    else if (lastMove == "right") {
        moveLeft();
    }
    else {
        std::cout << "Invalid move!" << std::endl;
    }
}

void Ghost::respawn()
{
    set_location(750, 400);
}