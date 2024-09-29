#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <raylib-cpp.hpp>
#include <iostream>
#include "GameOperations.h"


using namespace std;

auto temp=raylib::Window(1600, 900, "test window");

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
TEST_CASE("Player initializes correctly")
{
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
    player test = player{800, 300};
    test.moveUp();

    CHECK(test.get_y() == 300 - 5);
}

TEST_CASE("moveDown moves the player down")
{
    player test = player{800, 300};
    test.moveDown();

    CHECK(test.get_y() == 300 + 5);
}

TEST_CASE("moveLeft moves the player Left")
{
    player test = player{800, 300};
    test.moveLeft();

    CHECK(test.get_x() == 800 - 5);
}

TEST_CASE("moveRight moves the player Right")
{
    player test = player{800, 300};
    test.moveRight();

    CHECK(test.get_x() == 800 + 5);
}

TEST_CASE("moveRight moves the player Right")
{
    player test = player{800, 300};
    test.set_location(1451, 300);
    test.moveRight();

    CHECK(test.get_x() == 1451+5);
}
//====================================Testing collisions====================================================================================
TEST_CASE("check collision between sprites work")
{
    GameOperations game;
    game.checkCollisionPacmanGhost();
    CHECK(game.getCollision());
}

TEST_CASE("check collision between sprites work")
{
    player test = player{800, 300};
    vector<int> WallCoordinates= {1,1,10,10};
    int index = 0;
    GameOperations game;
    bool collision = false;

    if (CheckCollisionRecs(game.returnRect(index, WallCoordinates) ,test.getBoundingBox() )) {
        collision = true;
    }

    CHECK(!collision);
}

// TEST_CASE("Check collisions work if pacman Spawns inside a wall")
// {
//     GameOperations test;
//     test.loadRect("..resources/GameMap.txt");
//     player TestPlayer = player {50,0};
//     test.checkCollisionWall();

//     CHECK(test.getCollision());
// }