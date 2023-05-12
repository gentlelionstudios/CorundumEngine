//
// Created by Connor Gamble on 5/12/23.
//

#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>
#include "Vector2.h"
#include <iostream>

using namespace crn;

constexpr auto match = Catch::Matchers::WithinAbs;

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
    Vector2 v2(20.4132f, 5.6764f);
    Vector2 v3(85.12945f, 1.234f);

    CHECK_THAT(v1.magnitude(), match(6.3941, 0.0001));
    CHECK_THAT(v2.magnitude(), match(21.1877, 0.0001));
    CHECK_THAT(v3.magnitude(), match(85.1383, 0.0001));
}

TEST_CASE("Normalize method") {
    Vector2 v1(4.45f, 7.234f);

    CHECK_THAT(v1.normalize().magnitude(), match(1, 0.000000001));
    CHECK_THAT(v1.x_comp, match(0.5239, 0.0001));
    CHECK_THAT(v1.y_comp, match(0.8517, 0.0001));
}