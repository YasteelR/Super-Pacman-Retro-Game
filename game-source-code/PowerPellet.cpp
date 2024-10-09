#include "PowerPellet.h"

// Default constructor for the PowerPellet class.
PowerPellet::PowerPellet() : Sprite()
{
    set_sprite("../resources/powerPellet.png"); // Set the sprite image for the power pellet.
    active = 0; // Initialize the active state to inactive (0).
}

// Decrements the active counter if the power pellet is currently active.
void PowerPellet::duration()
{
    if (active > 0) // Check if the power pellet is active.
    {
        active--; // Reduce the active duration by one.
    }
}

// Checks if the power pellet is currently active.
bool PowerPellet::activePower()
{
    if (active > 0) // If the active counter is greater than 0,
    {
        return true; // it means the power pellet is active.
    }
    else 
        return false; // Otherwise, it's inactive.
}

// Activates the power pellet for a specific duration.
void PowerPellet::activate()
{
    active = 450; // Set the active state to 450 frames.
    set_location(-100, -100); // Move the power pellet off-screen.
}