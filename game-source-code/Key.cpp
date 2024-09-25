#include "Key.h"

Key::Key() : BaseObject()
{
    set_sprite("../resources/key.png");
}

void Key::set_location(int x, int y)
{
    current_x=x;
    current_y=y;
}