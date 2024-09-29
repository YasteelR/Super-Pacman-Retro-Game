#include "player.h"

player::player(int x, int y)
: Move(x,y)
{
    lives=3;
    setHearts();
    dead=false;
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


void player::loseLife()
{
    if(lives>=0)
    {
        hearts[lives-1]->set_location(-100,-100);
    }
    lives--;
    if(lives==0)
    {
        dead=true;
    }
}

bool player::isDead()
{
    return dead;
}

void player::setHearts()
{
    int w=750;
    int h=800;
    for(int i=0; i<lives; i++)
    {
        hearts.emplace_back(make_shared<BaseObject>());
        hearts.back()->set_location(w,h);
        hearts.back()->set_sprite("../resources/heart.png");
        w=w+55;
    }
}

shared_ptr<vector<shared_ptr<BaseObject>>> player::getHearts()
{
    auto pointer = make_shared<vector<shared_ptr<BaseObject>>>(hearts);
    return pointer;
}

