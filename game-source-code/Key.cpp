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
    //cout<<"Entered"<<endl;
    for(int j=ThisKeysNumber*8; j<(ThisKeysNumber*8+8); j++)
    {
        doors[j]=0;
        // cout<<j<<" ";
        // cout<<doors[j]<<" ";
    }
    //cout<<endl;
}

void Key::move_Obj()
{
    throw runtime_error("Keys cannot move!");
}

void Key::undoLastMove()
{
    throw runtime_error("Keys cannot move!");
}
