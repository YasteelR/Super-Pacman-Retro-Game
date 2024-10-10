#include "SuperPellet.h"

// Static member variable to track the number of active super pellets.
int SuperPellet::Super = 0;

// Constructor that initializes the SuperPellet object and its properties.
SuperPellet::SuperPellet() : Sprite()
{
    set_sprite("../resources/superPellet.png"); // Set the sprite for the super pellet.
    active = 0; // Initialize the active state to 0 (not active).
    Super = 0; // Reset the count of active super pellets.
    powerful = false; // Set the powerful state to false.
}

// Decreases the active duration of the super pellet and manages its powerful state.
void SuperPellet::duration()
{
    if(active > 0) // Check if the super pellet is currently active.
    {
        active--; // Decrease the active duration.
    }
    else if (active == 0 && powerful) // If active duration has expired and it's powerful.
    {
        Super--; // Decrease the count of active super pellets.
        powerful = false; // Set powerful state to false.
    }
}

// Checks if there is an active super pellet power.
bool SuperPellet::activePower()
{
    // Return true if there are active super pellets.
    if(Super > 0)
    {
        return true; // Power is active.
    }
    else 
        return false; // No active power.
}

// Activates the super pellet, setting it to active state and updating its properties.
void SuperPellet::activate()
{
    active = 480; // Set the active duration.
    powerful = true; // Mark the super pellet as powerful.
    Super++; // Increment the count of active super pellets.
    set_location(-100, -100); // Move the pellet out of view.
}