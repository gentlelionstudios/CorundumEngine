//
// Created by Connor Gamble on 5/12/23.
//

#ifndef CORUNDUMENGINE_VECTOR2_H
#define CORUNDUMENGINE_VECTOR2_H

#include <cmath>

namespace crn {

    struct Vector2 {
        float x_comp;
        float y_comp;

        constexpr Vector2() : x_comp(0.0), y_comp(0.0) {}

        constexpr Vector2(const float& x, const float& y) : x_comp(x), y_comp(y) {}

        Vector2& normalize();

        float magnitude() const;

    };

}


#endif //CORUNDUMENGINE_VECTOR2_H
