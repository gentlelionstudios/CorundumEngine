/*
 * Copyright (c) 2020 Gentle Lion Studios, Inc.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include "entity.h"

namespace corundum {
    void Entity::update(float deltaTime) {
        for (auto const& component : components) {
            component->update(deltaTime);
        }
    }

    void Entity::render(SDL_Renderer* renderer) {
        for (auto const& component : components) {
            component->render(renderer);
        }
    }

    void Entity::destroy() {
        active = false;
    }

    std::string_view Entity::getName() const {
        return name;
    }

    bool Entity::isActive() const {
        return active;
    }

    void Entity::addComponent(std::shared_ptr<Component> component) {
        components.push_back(component);
    }
}