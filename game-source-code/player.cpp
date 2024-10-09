#include "player.h"

player::player()
: Sprite()
{
    lives=4;
    cout<<lives<<endl;
    setHearts();
    dead=false;
    set_sprite("../resources/pacmanLeft.png");
    up = false;
    down = false;
    vertical = 0;
    right = false;
    left = false;
    horizontal = 0;
    speed = 2;
}

player::player(int x, int y)
: Sprite(x,y)
{
    lives=3;
    setHearts();
    dead=false;
    set_sprite("../resources/pacmanLeft.png");
    up = false;
    down = false;
    vertical = 0;
    right = false;
    left = false;
    horizontal = 0;
    speed = 2;
    newSpeed=speed;
}

void player::moveUp(){
    set_location(get_x(), get_y() - speed);

}

void player::moveDown() {
    set_location(get_x(), get_y() + speed);

}

void player::moveLeft() {
    set_location(get_x() - speed, get_y() );

}

void player::moveRight() {
    set_location(get_x() + speed, get_y() );
}


void player::move_Obj(){
    //cout<<horizontal<<" "<<vertical<<endl;
    if(vertical==0 && horizontal==0)
    {
        speed =newSpeed;
    }
        if((IsKeyDown(KEY_UP)||up)&&(!right&&!left)) {
            if(!up)
            {
                vertical = 50/speed - vertical;
                up=true;
                down = false;
            }
            if(vertical>0)
            {
                vertical--;
                if(vertical==0)
                {
                    up = false;
                }
                moveUp();
                lastMove = "up";
                return;
            }
        }
        else if((IsKeyDown(KEY_DOWN)||down)&&(!right&&!left)) {
            if(!down)
            {
                vertical = 50/speed - vertical;
                up=false;
                down = true;
            }
            if(vertical>0)
            {
                vertical--;
                if(vertical==0)
                {
                    down = false;
                }
                moveDown();
                lastMove = "down";
                return;
            }
        }
        if((IsKeyDown(KEY_RIGHT)||right)&&(!up&&!down)) {
            //cout<<"right"<<endl;
            if(!right)
            {
                horizontal = 50/speed - horizontal;
                right=true;
                left = false;
            }
            if(horizontal>0)
            {
                horizontal--;
                if(horizontal==0)
                {
                    right = false;
                }
                moveRight();
                lastMove = "right";
                return;
            }
        }
        else if((IsKeyDown(KEY_LEFT)||left)&&(!up&&!down)) {
            if(!left)
            {
                horizontal = 50/speed - horizontal;
                right=false;
                left = true;
            }
            if(horizontal>0)
            {
                horizontal--;
                if(horizontal==0)
                {
                    left = false;
                }
                moveLeft();
                lastMove = "left";
                return;
            }
        }
}

void player::undoLastMove() {
    resetMovers();
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
        lives--;
    }
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

void player::resetMovers()
{
    up=false;
    down=false;
    right=false;
    left=false;
    vertical=0;
    horizontal=0;
}

void player::setSpeed(int velocity)
{
    if(50%velocity==0)
    {
        newSpeed=velocity;
    }
    else 
        throw runtime_error("Velocity must be an integer multiple of 50");
}