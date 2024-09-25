#include "Ghost.h"

Ghost::Ghost(int x, int y)
: BaseObject(x,y)
{
    auto object_feature = get_Properties();
    object_feature.is_player = true;
    set_Properties(object_feature);
    set_sprite("../resources/Ghost.png");
}

void Ghost::move_Obj(){
    cout <<"Ghost moved"<<endl;
};
