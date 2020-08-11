/*
 * Copyright (c) 2020 Gentle Lion Studios, Inc.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include "transform_component.h"
#include <SDL2/SDL_rect.h>
#include <fmt/core.h>

namespace corundum {
    void TransformComponent::update(float deltaTime) {
        position =
            glm::vec2(position.x + velocity.x * deltaTime, position.y + velocity.y * deltaTime);
    }

    void TransformComponent::render(SDL_Renderer* renderer) {
        SDL_Rect rectangle {static_cast<int>(position.x), static_cast<int>(position.y), width,
                            height};

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderFillRect(renderer, &rectangle);
    }
    std::string TransformComponent::toString() {
        return fmt::format("projectile: x={}, y={}\n"
                           "velocity: x={}, y={}\n"
                           "height: {}\n"
                           "width: {}\n"
                           "scale: {}\n",
                           position.x, position.y, velocity.x, velocity.y, height, width, scale);
    }
}