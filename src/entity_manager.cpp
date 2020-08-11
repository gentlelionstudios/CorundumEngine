/*
 * Copyright (c) 2020 Gentle Lion Studios, Inc.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include "entity_manager.h"

namespace corundum {
    void EntityManager::update(float deltaTime) {
        for (auto const& entity : entities) {
            entity->update(deltaTime);
        }
    }

    void EntityManager::render(SDL_Renderer* renderer) {
        for (auto const& entity : entities) {
            entity->render(renderer);
        }
    }

    std::shared_ptr<Entity> EntityManager::addEntity(std::string_view entityName) {
        auto entity = std::make_shared<Entity>(entityName);
        entities.push_back(entity);
        return entity;
    }
    bool EntityManager::empty() const {
        return entities.empty();
    }
}