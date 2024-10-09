#include "Key.h"

// Static member initialization for the number of keys.
int Key::NumberOfKeys = 0;

Key::Key() : Sprite()
{
    set_sprite("../resources/key.png"); // Set the sprite for the key using the specified resource path.
    ThisKeysNumber = NumberOfKeys; // Assign the current key's number based on the total keys.
    NumberOfKeys++; // Increment the total number of keys.
}

void Key::destroyDoors(vector<shared_ptr<Door>>& doors)
{
    // Iterate over the doors associated with this key and destroy them.
    for(int i = ThisKeysNumber * 2; i < ThisKeysNumber * 2 + 2; i++)
    {
        doors[i]->set_location(0, 0); // Move the door to (0,0).
        doors[i]->setWidth(0); // Set the door width to 0.
        doors[i]->setHeight(0); // Set the door height to 0 (corrected from setting width twice).
    }
}