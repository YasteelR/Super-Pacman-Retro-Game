#include "Key.h"

Key::Key(int x, int y) : BaseObject(x,y)
{
    set_location(x,y);
}

void Key::set_location(int x, int y)
{
    current_x=x;
    current_y=y;
}