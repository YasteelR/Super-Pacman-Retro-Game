#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <raylib-cpp.hpp>
#include <iostream>
#include "GameMode.h"
#include "BaseObject.h"
#include "GameOperations.h"
#include "Player.h"
#include "Ghost.h"

TEST_CASE("check cake ")
{

    CHECK(1 == 1);
}

//====================================Testing BaseObject class=====================================================================
// TEST_CASE("Base Object Initializes correctly")
// {
//     //This test needs to be altered later
//     BaseObject test=BaseObject{0,0};
//     tuple<bool, bool, bool> TestConditions(false, false, false);

//     if(test.get_x()==0 && test.get_y()==0)
//     {
//         get<0>(TestConditions)=true;
//     }

//     if(test.get_sprite()=="")
//     {
//         get<1>(TestConditions)=true;
//     }

//     if(get<0>(TestConditions)==get<1>(TestConditions))
//     {
//         get<2>(TestConditions)=true;
//     }

//     CHECK(get<2>(TestConditions));
// }

// TEST_CASE("Set Location updates objects location")
// {
//     BaseObject test = BaseObject{0,0};

//     int x=1;
//     int y=1;

//     test.set_location(x,y);

//     bool testCase=false;

//     if(test.get_x()==x && test.get_y()==y)
//     {
//         testCase=true;
//     }

//     CHECK(testCase);
// }

// TEST_CASE("Set sprite changes sprite to filename")
//{
//     BaseObject test = BaseObject{0,0};
//     string spriteTestName="bobbbyyyyyy";
//
//     test.set_sprite(spriteTestName);
//
//     CHECK(test.get_sprite()==spriteTestName);
// }

// TEST_CASE("Set_moved shows if the object has been moved")
// {
//     BaseObject test = BaseObject{0,0};
//     test.set_moved(true);

//     Properties check=test.get_Properties();

//     CHECK(check.is_moved);
// }

//====================================Testing Player====================================================================================
TEST_CASE("GameOperations initializes correctly")
{
    raylib::Window(1600, 900, "test window");
    player test = player(0, 0);

    int xPosition = 0;
    int yPosition = 0;

    bool check = false;
    if (test.get_x() == xPosition && test.get_y() == yPosition)
    {
        check = true;
    }

    CHECK(check);
}

TEST_CASE("moveUp moves the player up")
{
    raylib::Window(1600, 900, "test window");
    player test = player{800, 300};
    test.moveUp();

    CHECK(test.get_y() == 300 - 5);
}

TEST_CASE("moveUp will not move the player off the screen")
{
    raylib::Window(1600, 900, "test window");
    player test = player{800, 300};
    test.set_location(800, 9);
    test.moveUp();

    CHECK(test.get_y() == 9);
}

TEST_CASE("moveDown moves the player down")
{
    raylib::Window(1600, 900, "test window");
    player test = player{800, 300};
    test.moveDown();

    CHECK(test.get_y() == 300 + 15);
}

TEST_CASE("moveDown will not move the player off screen")
{
    player test = player{800, 300};
    test.set_location(800, 756);
    test.moveDown();

    CHECK(test.get_y() == 756);
}

TEST_CASE("moveLeft moves the player Left")
{
    raylib::Window(1600, 900, "test window");
    player test = player{800, 300};
    test.moveLeft();

    CHECK(test.get_x() == 800 - 15);
}

TEST_CASE("moveLeft will not move the player off screen")
{
    raylib::Window(1600, 900, "test window");
    player test = player{800, 300};
    test.set_location(4, 300);
    test.moveLeft();

    CHECK(test.get_x() == 4);
}

TEST_CASE("moveRight moves the player Right")
{
    raylib::Window(1600, 900, "test window");
    player test = player{800, 300};
    test.moveRight();

    CHECK(test.get_x() == 800 + 15);
}

TEST_CASE("moveRight moves the player Right")
{
    raylib::Window(1600, 900, "test window");
    player test = player{800, 300};
    test.set_location(1451, 300);
    test.moveRight();

    CHECK(test.get_x() == 1466);
}
//====================================Testing collisions====================================================================================
TEST_CASE("check collision between sprites work")
{
    GameOperations game;

    CHECK(!game.checkCollisionPacmanGhost());
}
TEST_CASE("check collision between sprites work")
{
    raylib::Window(1600, 900, "test window");
    player test = player{800, 300};
    vector<int> WallCoordinates= {1,1,10,10};
    int index = 0;
    GameOperations game;
    bool collision = false;

    if (CheckCollisionRecs(game.returnRect(index, WallCoordinates) ,test.getBoundingBox() )) {
        //cout <<"wall collision"<<endl;
        collision = true;
    }

    CHECK(!collision);
}