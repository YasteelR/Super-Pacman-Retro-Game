#include "Pellet.h"

Pellet::Pellet() : BaseObject()
{
    auto object_feature = get_Properties();
    set_Properties(object_feature);
}