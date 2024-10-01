#include "player.h"

player::player(int x, int y)
: Sprite(x,y)
{
    lives=3;
    setHearts();
    dead=false;
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
    int w=200;
    int h=800;
    for(int i=0; i<lives; i++)
    {
        hearts.emplace_back(make_shared<Sprite>());
        hearts.back()->set_location(w,h);
        hearts.back()->set_sprite("../resources/heart.png");
        w=w+55;
    }
}

shared_ptr<vector<shared_ptr<Sprite>>> player::getHearts()
{
    auto pointer = make_shared<vector<shared_ptr<Sprite>>>(hearts);
    return pointer;
}

