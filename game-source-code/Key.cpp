#include "Key.h"

int Key::NumberOfKeys=0;

Key::Key() : Sprite()
{
    setSprite("../resources/key.png");
    ThisKeysNumber=NumberOfKeys;
    NumberOfKeys++;
}

void Key::destroyDoors(vector<shared_ptr<Door>>& doors)
{
    for(int i=ThisKeysNumber*2; i<ThisKeysNumber*2+2; i++)
    {
        doors[i]->set_location(0,0);
        doors[i]->setWidth(0);
        doors[i]->setWidth(0);
    }
}
