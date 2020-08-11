/*
 * Copyright (c) 2020 Gentle Lion Studios, Inc.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#pragma once

#include "entity_manager.h"
#include "ticks.h"
#include <SDL2/SDL.h>

namespace corundum {
    class Game {
      public:
        Game();
        ~Game();
        [[nodiscard]] bool isRunning() const;
        void initialize(int width, int height);
        void runLoop();
        void destroy();

      private:
        void processInput();
        void update(float deltaTime);
        void render();
        void loadLevel();

        bool gameIsRunning;
        SDL_Window* window;
        SDL_Renderer* renderer;
        Ticks ticks;
        EntityManager manager;
    };
}