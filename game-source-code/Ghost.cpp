#include "Ghost.h"

Ghost::Ghost(int x, int y)
: BaseObject(x,y)
{
    current_x = 800;
    current_y = 300;
    auto object_feature = get_Properties();
    object_feature.is_player = true;
    set_Properties(object_feature);
    set_sprite("resources/Ghost.png");
}

void Ghost::move_Obj(){
    cout <<"Ghost"<<endl;
};
