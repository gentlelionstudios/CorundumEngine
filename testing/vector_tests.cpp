//
// Created by Connor Gamble on 5/12/23.
//

#include <catch2/catch_test_macros.hpp>
#include "Vector2.h"

using namespace crn;

TEST_CASE("Default Constructor Initialization") {
    Vector2 v;
    CHECK(v.x_comp == 0);
    CHECK(v.y_comp == 0);
}

TEST_CASE("Argument Constructor Initialization") {
    Vector2 v(3.45f, 6.21f);

    CHECK(v.x_comp == 3.45f);
    CHECK(v.y_comp == 6.21f);
}

TEST_CASE("Magnitude Method") {
    Vector2 v1(5.53f, 3.21f);

    CHECK(v1.magnitude() == 6.39f);
}