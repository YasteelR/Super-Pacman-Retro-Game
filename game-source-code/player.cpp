#include "player.h"

player::player(int x, int y)
: BaseObject(x,y)
{
    current_x = 800;
    current_y = 300;
    auto object_feature = get_Properties();
    object_feature.is_player = true;
    set_Properties(object_feature);
    set_sprite("resources/pacmanLeft.png");
}

void player::moveUp(){
        if (get_y() > 10) {
            set_location(get_x(), get_y() - 15);

            //cout<<get_y()<<endl;
        }  
    }

void player::moveDown() {
         if (get_y() < 755) {
            set_location(get_x(), get_y() + 15);
        }
    }

void player::moveLeft() {
         if (get_x() > 5) {
            set_location(get_x() - 15, get_y() );
            //set_sprite("resources/pacmanLeft.png");
        }
    }

void player::moveRight() {
         if (get_x() < 1450) {
            set_location(get_x() + 15, get_y() );
            //set_sprite("resources/pacmanRight.png");
            //cout<<get_x()<<endl;
        }
    }


void player::move_Obj(){
    /*
    window = get_window();

    window->pollEvent(event);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        moveUp();
        //set_moved(true);
    // is_moved = true;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        moveDown();
        //set_moved(true);
       // player.is_moved = true;

}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        moveRight();
        //set_moved(true);
        //player.is_moved = true;
}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        moveLeft();
       // set_moved(true);
        //player.is_moved = true;
}*/
}

