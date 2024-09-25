#include "Ghost.h"

Ghost::Ghost(int x, int y)
: BaseObject(x,y)
{
    auto object_feature = get_Properties();
    object_feature.is_player = true;
    set_Properties(object_feature);
    set_sprite("../resources/Ghost.png");
}

void Ghost::move_Obj(){
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