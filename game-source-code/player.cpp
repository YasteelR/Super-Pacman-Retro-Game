#include "player.h"

player::player(int x, int y)
: BaseObject(x,y)
{

    auto object_feature = get_Properties();
    object_feature.is_player = true;
    set_Properties(object_feature);
    set_sprite("../resources/pacmanLeft.png");
}

void player::moveUp(){
    set_location(get_x(), get_y() - 5);

}

void player::moveDown() {
    set_location(get_x(), get_y() + 5);

}

void player::moveLeft() {
    set_location(get_x() - 5, get_y() );

}

void player::moveRight() {
    set_location(get_x() + 5, get_y() );
}


void player::move_Obj(){
        if(IsKeyDown(KEY_UP)) {
            moveUp();
            lastMove = "up";
            return;
        }
        else if(IsKeyDown(KEY_DOWN)) {
            moveDown();
            lastMove = "down";
            return;
        }
        if(IsKeyDown(KEY_RIGHT)) {
            moveRight();
            lastMove = "right";
            return;
        }
        else if(IsKeyDown(KEY_LEFT)) {
            moveLeft();
            lastMove = "left";
            return;
        }
        updatePlayerGameData();
}

void player::undoLastMove() {
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
        //std::cout << "Invalid move!" << std::endl;
    }
}


