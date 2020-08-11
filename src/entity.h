/*
 * Copyright (c) 2020 Gentle Lion Studios, Inc.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#pragma once

#include "component.h"
#include <memory>
#include <string>
#include <vector>

namespace corundum {
    class Entity {
      public:
        explicit Entity(std::string_view aName) : name {aName}, active {true} {}

        void update(float deltaTime);
        void render(SDL_Renderer* renderer);
        void destroy();
        [[nodiscard]] std::string_view getName() const;
        [[nodiscard]] bool isActive() const;
        void addComponent(std::shared_ptr<Component> component);

      private:
        std::string name;
        bool active;
        std::vector<std::shared_ptr<Component>> components;
    };
}