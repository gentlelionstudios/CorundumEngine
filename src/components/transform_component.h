/*
 * Copyright (c) 2020 Gentle Lion Studios, Inc.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#pragma once

#include "../component.h"
#include <glm/glm.hpp>

namespace corundum {
    class TransformComponent : public Component {
      public:
        TransformComponent(int posX, int posY, int velX, int velY, int w, int h, int s)
            : position {glm::vec2(posX, posY)}, velocity {glm::vec2(velX, velY)}, width {w},
              height {h}, scale {s} {}

        void initialize() override {}
        void update(float deltaTime) override;
        void render(SDL_Renderer* renderer) override;
        std::string toString();

      private:
        glm::vec2 position;
        glm::vec2 velocity;
        int width;
        int height;
        int scale;
    };
}
