#include "Ghost.h"

Ghost::Ghost(int x, int y)
: Sprite(x,y)
{
    set_sprite("../resources/Ghost.png");
    vert = true;
    hor = true;
    xSpawn=x;
    ySpawn=y;
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

void Ghost::move_Obj(shared_ptr<player> pacman){
    auto playerX = pacman->get_x();
    auto playerY = pacman->get_y();

    auto xDistance = playerX - get_x();
    auto yDistance = playerY - get_y();
    //cout << xDistance<<"    "<<yDistance<<"  "<<hor<< "   " << vert<<endl;
    if (xDistance > 0 && hor){
        moveRight();
        lastMove = "right";
        return;
    } if (xDistance < 0 && hor){
        moveLeft();
        lastMove = "left";
        return;
    } if (yDistance < 0 && vert){
        moveUp();
        lastMove = "up";
        return;
    } if ( yDistance > 0 && vert){
        moveDown();
        lastMove = "down";
        return;
    }
    vert =true;
    hor = true;
};

void Ghost::undoLastMove() {
    
    if (lastMove == "up") {
        moveDown();
        vert =false;
    }
    else if (lastMove == "down") {
        moveUp();
        vert = false;
    }
    else if (lastMove == "left") {
       moveRight();
       hor = false;
    }
    else if (lastMove == "right") {
        moveLeft();
        hor = false;
    }
    else {
        std::cout << "Invalid move!" << std::endl;
    }
}

void Ghost::respawn()
{
    set_location(xSpawn, ySpawn);
}