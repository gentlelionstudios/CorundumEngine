//
// Created by Connor Gamble on 5/12/23.
//

#include "Vector2.h"

/*
 * Divide x & y by magnitude to squish components into unit space [0, 1]
 */

crn::Vector2 &crn::Vector2::normalize() {
    float v_magnitude = magnitude();
    x_comp /= v_magnitude;
    y_comp /= v_magnitude;
    return *this;
}

/*
 * |V| = sqrt( x^2 + y^2 )
 */

inline float crn::Vector2::magnitude() const {
    return static_cast<float>(sqrt(pow(x_comp, 2) + pow(y_comp, 2)));
}
