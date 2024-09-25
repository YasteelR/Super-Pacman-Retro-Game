#include "Ghost.h"

Ghost::Ghost(int x, int y)
: BaseObject(x,y)
{
    auto object_feature = get_Properties();
    object_feature.is_player = true;
    set_Properties(object_feature);
    set_sprite("../resources/Ghost.png");
}

void Ghost::moveUp(){
    set_location(get_x(), get_y() - 10);

}

void Ghost::moveDown() {
    set_location(get_x(), get_y() + 10);

}

void Ghost::moveLeft() {
    set_location(get_x() - 10, get_y() );

}

void Ghost::moveRight() {
    set_location(get_x() + 10, get_y() );
}

void Ghost::move_Obj(){
    auto playerX = getPlayerX();
    auto playerY = getPlayerY();

    auto xDistance = playerX - get_x();
    auto yDistance = playerY - get_y();
    if (xDistance > 0 && yDistance > 0){
        moveDown();
        moveRight();
    }else if (xDistance < 0 && yDistance < 0){
        moveLeft();
        moveUp();
    }else if (xDistance > 0 && yDistance < 0){
        moveRight();
        moveUp();
    }else if (xDistance < 0 && yDistance > 0){
        moveDown();
        moveLeft();
    }

};

void Ghost::undoLastMove() {
    if (lastMove == "up") {
        //moveDown();
    }
    else if (lastMove == "down") {
        //moveUp();
    }
    else if (lastMove == "left") {
       //moveRight();
    }
    else if (lastMove == "right") {
        //moveLeft();
    }
    else {
        std::cout << "Invalid move!" << std::endl;
    }
}