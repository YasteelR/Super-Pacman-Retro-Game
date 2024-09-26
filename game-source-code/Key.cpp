#include "Key.h"

int Key::NumberOfKeys=0;

Key::Key() : BaseObject()
{
    set_sprite("../resources/key.png");
    ThisKeysNumber=NumberOfKeys;
    NumberOfKeys++;
    //cout<<NumberOfKeys<<endl;
}

void Key::destroyDoors(vector<int>& doors)
{
    for(int i=ThisKeysNumber*8; i<ThisKeysNumber+8; i++)
    {
        doors[i]=0;
    }
}

void Key::move_Obj()
{
    throw runtime_error("Keys cannot move!");
}

void Key::undoLastMove()
{
    throw runtime_error("Keys cannot move!");
}
