#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <raylib-cpp.hpp>
#include <iostream>
#include "GameMode.h"
#include "GameMap.h"
#include "BaseObject.h"

TEST_CASE("check cake "){

    CHECK(1==1);
}

//====================================Testing GameMap==============================================
TEST_CASE("Check that GameMap initializes correctly")
{
    GameMap test;
    string testFile="../resources/GameMap.txt";
    test.OpenFile(testFile);
    CHECK(test.FileIsOpen());
}

TEST_CASE("Check that GameMap returns false if file not open")
{
    GameMap test;
    string testFile="";
    test.OpenFile(testFile);

    CHECK_FALSE(test.FileIsOpen());
}

TEST_CASE("If a file is open and you try open another it throws and error")
{
    GameMap test;
    string testFile1="../resources/GameMap.txt";
    test.OpenFile(testFile1);

    CHECK_THROWS_AS(test.OpenFile(testFile1),std::runtime_error);
}

TEST_CASE("If file does not contain data in the correct format it throws an error")
{
    GameMap test;
    string testFile="test-source-code/GameMapTest1.txt";
    test.OpenFile(testFile);

    CHECK_THROWS_AS(test.ReadData(),std::runtime_error);
}

//====================================Testing BaseObject class=====================================================================
TEST_CASE("Base Object Initializes correctly")
{
    //This test needs to be altered later
    BaseObject test=BaseObject{0,0};
    tuple<bool, bool, bool> TestConditions(false, false, false);

    if(test.get_x()==0 && test.get_y()==0)
    {
        get<0>(TestConditions)=true;
    }

    if(test.get_sprite()=="")
    {
        get<1>(TestConditions)=true;
    }

    if(get<0>(TestConditions)==get<1>(TestConditions))
    {
        get<2>(TestConditions)=true;
    }

    CHECK(get<2>(TestConditions));
}

