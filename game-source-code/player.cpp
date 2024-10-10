#include "player.h"

player::player()
: Sprite()
{
    lives = 4; // Set initial lives to 4.
    cout << lives << endl; // Print the initial number of lives.
    setHearts(); // Initialize heart display for lives.
    dead = false; // Player is initially alive.
    set_sprite("../resources/pacmanLeft.png"); // Set the initial sprite image.
    
    // Initialize movement flags and counters.
    up = false;
    down = false;
    vertical = 0; // Vertical movement counter.
    right = false;
    left = false;
    horizontal = 0; // Horizontal movement counter.
    speed = 2; // Set the speed of the player.
    newSpeed = speed;
    png.emplace_back("../resources/pacmanLeft.png");
    png.emplace_back("../resources/pacmanRight.png");
    png.emplace_back("../resources/pacmanUp.png");
    png.emplace_back("../resources/pacmanDown.png");
}

player::player(int x, int y)
: Sprite(x, y)
{
    lives = 3; // Set initial lives to 3.
    setHearts(); // Initialize heart display for lives.
    dead = false; // Player is initially alive.
    set_sprite("../resources/pacmanLeft.png"); // Set the initial sprite image.
    
    // Initialize movement flags and counters.
    up = false;
    down = false;
    vertical = 0;
    right = false;
    left = false;
    horizontal = 0;
    speed = 2; // Set the speed of the player.
    newSpeed = speed; // Set newSpeed to the initial speed.
    png.emplace_back("../resources/pacmanLeft.png");
    png.emplace_back("../resources/pacmanRight.png");
    png.emplace_back("../resources/pacmanUp.png");
    png.emplace_back("../resources/pacmanDown.png");
}

void player::moveUp(){
    set_location(get_x(), get_y() - speed); // Move the player up by the speed amount.
}

void player::moveDown() {
    set_location(get_x(), get_y() + speed); // Move the player down by the speed amount.
}

void player::moveLeft() {
    set_location(get_x() - speed, get_y()); // Move the player left by the speed amount.
}

void player::moveRight() {
    set_location(get_x() + speed, get_y()); // Move the player right by the speed amount.
}

void player::move_Obj(){
    // If there's no current movement, reset speed.
    if(vertical == 0 && horizontal == 0)
    {
        speed = newSpeed; // Restore original speed.
    }
    
    // Handle upward movement.
    if((IsKeyDown(KEY_UP) || up) && (!right && !left)) {
        set_sprite(png[2]);
        if(!up) // If not already moving up, calculate vertical movement.
        {
            vertical = 50/speed - vertical; // Determine how much to move up.
            up = true; // Set moving up flag.
            down = false; // Reset down flag.
        }
        if(vertical > 0) // Continue moving up until the counter reaches zero.
        {
            vertical--;
            if(vertical == 0) // Reset moving up flag when done.
            {
                up = false;
            }
            moveUp(); // Move player up.
            lastMove = "up"; // Record the last move direction.
            return; // Exit the function.
        }
    }
    
    // Handle downward movement.
    else if((IsKeyDown(KEY_DOWN) || down) && (!right && !left)) {
        set_sprite(png[3]);
        if(!down) // If not already moving down, calculate vertical movement.
        {
            vertical = 50/speed - vertical;
            up = false; // Reset up flag.
            down = true; // Set moving down flag.
        }
        if(vertical > 0) // Continue moving down until the counter reaches zero.
        {
            vertical--;
            if(vertical == 0) // Reset moving down flag when done.
            {
                down = false;
            }
            moveDown(); // Move player down.
            lastMove = "down"; // Record the last move direction.
            return; // Exit the function.
        }
    }
    
    // Handle right movement.
    if((IsKeyDown(KEY_RIGHT) || right) && (!up && !down)) {
        set_sprite(png[1]);
        if(!right) // If not already moving right, calculate horizontal movement.
        {
            horizontal = 50/speed - horizontal; // Determine how much to move right.
            right = true; // Set moving right flag.
            left = false; // Reset left flag.
        }
        if(horizontal > 0) // Continue moving right until the counter reaches zero.
        {
            horizontal--;
            if(horizontal == 0) // Reset moving right flag when done.
            {
                right = false;
            }
            moveRight(); // Move player right.
            lastMove = "right"; // Record the last move direction.
            return; // Exit the function.
        }
    }
    // Handle left movement.
    else if((IsKeyDown(KEY_LEFT) || left) && (!up && !down)) {
        set_sprite(png[0]);
        if(!left) // If not already moving left, calculate horizontal movement.
        {
            horizontal = 50/speed - horizontal; // Determine how much to move left.
            right = false; // Reset right flag.
            left = true; // Set moving left flag.
        }
        if(horizontal > 0) // Continue moving left until the counter reaches zero.
        {
            horizontal--;
            if(horizontal == 0) // Reset moving left flag when done.
            {
                left = false;
            }
            moveLeft(); // Move player left.
            lastMove = "left"; // Record the last move direction.
            return; // Exit the function.
        }
    }
}

void player::undoLastMove() {
    resetMovers(); // Reset movement flags and counters.
    // Undo the last move based on the last recorded direction.
    if (lastMove == "up") {
        moveDown(); // Move down to undo up.
    }
    else if (lastMove == "down") {
        moveUp(); // Move up to undo down.
    }
    else if (lastMove == "left") {
        moveRight(); // Move right to undo left.
    }
    else if (lastMove == "right") {
        moveLeft(); // Move left to undo right.
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