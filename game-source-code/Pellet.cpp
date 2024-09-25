#include "Pellet.h"

Pellet::Pellet(int x, int y) : BaseObject(x,y)
{
    auto object_feature = get_Properties();
    set_Properties(object_feature);
}