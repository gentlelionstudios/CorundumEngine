/*
 * Copyright (c) 2020 Gentle Lion Studios, Inc.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#pragma once

#include <SDL2/SDL_render.h>
#include <memory>

namespace corundum {
    class Component {
      public:
        virtual ~Component() = default;

        virtual void initialize() {}
        virtual void update(float deltaTime) {}
        virtual void render(SDL_Renderer* renderer) {}

      private:
    };
}
