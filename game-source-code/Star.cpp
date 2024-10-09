#include "Star.h"

// Constructor that initializes the Star object and its associated sprites.
Star::Star() : Sprite()
{
    set_sprite("../resources/star.png"); // Set the main sprite to a star image.
    srand(time(0)); // Seed the random number generator with the current time.
    clock = 0; // Initialize the clock for timing.
    timer = 60; // Set the timer duration for changing fruit sprites.

    // Add different fruit file paths to the vector for random selection.
    fruitsFilepath.emplace_back("../resources/banana.png");
    fruitsFilepath.emplace_back("../resources/orange.png");
    fruitsFilepath.emplace_back("../resources/cherry.png");

    // Create the first star fruit sprite and set its image.
    starFruits.emplace_back(make_shared<Sprite>());
    starFruits.back()->set_sprite(fruitsFilepath[0]);

    // Create the second star fruit sprite and set its image.
    starFruits.emplace_back(make_shared<Sprite>());
    starFruits.back()->set_sprite(fruitsFilepath[1]);

    // Set the initial locations of the fruit sprites.
    starFruits[0]->set_location(801, 601);
    starFruits[1]->set_location(701, 601);
}

// Updates the objects' states and changes the fruit sprites based on the timer.
void Star::setObjects()
{
    clock++; // Increment the clock with each call.
    if (clock == timer) // Check if the timer has reached the set duration.
    {
        clock = 0; // Reset the clock.
        for (int i = 0; i < starFruits.size(); i++)
        {
            int temp = rand() % 3; // Generate a random index for the fruits.
            starFruits[i]->set_sprite(fruitsFilepath[temp]); // Change the sprite to a random fruit.
        }
    }
}

// Checks if the two star fruits have the same sprite.
bool Star::CompanionsMatch()
{
    // Compare the sprites of the two fruit companions and return true if they match.
    if (starFruits[0]->getSprite() == starFruits[1]->getSprite())
    {
        return true; // Sprites match.
    }
    else 
        return false; // Sprites do not match.
}

// Checks if both star fruits are bananas.
bool Star::CompanionsMatchFruit()
{
    string check; // Variable to hold the banana sprite path.
    check = "../resources/banana.png"; // Set the path for comparison.
    
    // Check if both fruit companions are bananas.
    if (starFruits[0]->getSprite() == check && starFruits[1]->getSprite() == check)
    {
        return true; // Both fruits are bananas.
    }
    else
        return false; // Fruits are not both bananas.
}

// Moves the star and its companions out of view.
void Star::Destroy()
{
    set_location(-100, -100); // Move the star out of view.
    for (int i = 0; i < starFruits.size(); i++)
    {
        starFruits[i]->set_location(-100, -100); // Move each companion out of view.
    }
}

// Returns a shared pointer to a vector containing the fruit companions.
shared_ptr<vector<shared_ptr<Sprite>>> Star::getCompanions()
{
    auto pointer = make_shared<vector<shared_ptr<Sprite>>>(starFruits); // Create a shared pointer to the vector of companions.
    return pointer; // Return the pointer.
}

// Sets the timer duration for changing fruit sprites.
void Star::setTimer(int duration)
{
    timer = duration; // Update the timer duration.
}