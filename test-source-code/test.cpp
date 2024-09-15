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