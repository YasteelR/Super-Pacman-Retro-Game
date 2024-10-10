#include "PowerPellet.h"

// Static member variable to track the number of active power pellets.
int PowerPellet::Power = 0;

// Default constructor for the PowerPellet class.
PowerPellet::PowerPellet() : Sprite()
{
    set_sprite("../resources/powerPellet.png"); // Set the sprite image for the power pellet.
    active = 0; // Initialize the active state to inactive (0).
    Power = 0; // Reset the count of active power pellets.
    powerful = false; // Set the powerful state to false.
}

// Decrements the active counter if the power pellet is currently active.
void PowerPellet::duration()
{
    if (active > 0) // Check if the power pellet is active.
    {
        active--; // Reduce the active duration by one.
    }
    else if (active == 0 && powerful) // If active duration has expired and it's powerful.
    {
        Power--; // Decrease the count of active super pellets.
        powerful = false; // Set powerful state to false.
    }
}

// Checks if the power pellet is currently active.
bool PowerPellet::activePower()
{
    // Return true if there are active power pellets.
    if(Power > 0)
    {
        return true; // Power is active.
    }
    else 
        return false; // No active power.
}

// Activates the power pellet for a specific duration.
void PowerPellet::activate()
{
    active = 480; // Set the active duration.
    powerful = true; // Mark the power pellet as powerful.
    Power++; // Increment the count of active power pellets.
    set_location(-100, -100); // Move the pellet out of view.
}