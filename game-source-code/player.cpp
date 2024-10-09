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
    if(lives >= 0) // Ensure lives are valid before decrementing.
    {
        hearts[lives-1]->set_location(-100, -100); // Move the heart off-screen.
        lives--; // Decrease the number of lives.
    }
    if(lives == 0) // Check if player is out of lives.
    {
        dead = true; // Set the dead state to true.
    }
}

bool player::isDead()
{
    return dead; // Return the current dead state.
}

void player::setHearts()
{
    int w = 200; // Initial x position for hearts.
    int h = 800; // y position for hearts.
    for(int i = 0; i < lives; i++) // Create hearts based on lives.
    {
        hearts.emplace_back(make_shared<Sprite>()); // Create a new heart sprite.
        hearts.back()->set_location(w, h); // Set heart position.
        hearts.back()->set_sprite("../resources/heart.png"); // Set heart sprite image.
        w = w + 55; // Update x position for the next heart.
    }
}

shared_ptr<vector<shared_ptr<Sprite>>> player::getHearts()
{
    auto pointer = make_shared<vector<shared_ptr<Sprite>>>(hearts); // Create a shared pointer for hearts.
    return pointer; // Return the shared pointer.
}

void player::resetMovers()
{
    up = false; // Reset up movement flag.
    down = false; // Reset down movement flag.
    right = false; // Reset right movement flag.
    left = false; // Reset left movement flag.
    vertical = 0; // Reset vertical movement counter.
    horizontal = 0; // Reset horizontal movement counter.
}

void player::setSpeed(int velocity)
{
    // Ensure velocity is a multiple of 50 before setting.
    if (50 % velocity == 0) {
        newSpeed = velocity; // Set the new speed.
    }
    else {
        throw runtime_error("Velocity must be an integer multiple of 50"); // Throw an error if the condition is not met.
    }
}