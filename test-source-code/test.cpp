#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <raylib-cpp.hpp>
#include <iostream>
#include "GameMode.h"
#include "GameMap.h"

TEST_CASE("check cake "){

    CHECK(1==1);
}

TEST_CASE("Check that GameMap initializes correctly")
{
    GameMap test;
    string testFile="game-source-code/GameMap.txt";
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
    string testFile1="game-source-code/GameMap.txt";
    test.OpenFile(testFile1);

    CHECK_THROWS_AS(test.OpenFile(testFile1),std::runtime_error);
}

TEST_CASE("If file does not contain data in the correct format it throws an error")
{
    GameMap test;
    string testFile="test-source-code/GameMapTest.txt";
    test.OpenFile(testFile);

    CHECK_THROWS_AS(test.ReadData(),std::runtime_error);
}

