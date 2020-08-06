/*
 * Copyright (c) 2020 Gentle Lion Studios, Inc.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include "game.h"
#include <fmt/core.h>
#include <glm/glm.hpp>
#include <iostream>

namespace corundum {
    class Projectile {
      public:
        Projectile(float posX, float posY, float velX, float velY) {
            position = glm::vec2(posX, posY);
            velocity = glm::vec2(velX, velY);
        }
        ~Projectile() = default;

        void move(float deltaTime) {
            position =
                glm::vec2(position.x + velocity.x * deltaTime, position.y + velocity.y * deltaTime);
        }

        [[nodiscard]] float getX() const {
            return position.x;
        }

        [[nodiscard]] float getY() const {
            return position.y;
        }

        std::string toString() {
            return fmt::format("projectile: x={}, y={}\n"
                               "velocity: x={}, y={}\n",
                               position.x, position.y, velocity.x, velocity.y);
        }

      private:
        glm::vec2 position;
        glm::vec2 velocity;
    };

    Projectile projectile {0.0f, 0.0f, 20.0f, 20.0f};

    Game::Game() {
        gameIsRunning = false;
        window        = nullptr;
        renderer      = nullptr;
    }

    Game::~Game() = default;

    bool Game::isRunning() const {
        return gameIsRunning;
    }

    void Game::initialize(int width, int height) {
        if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
            std::cerr << "Error initializing SDL." << std::endl;
            return;
        }
        window = SDL_CreateWindow(nullptr, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width,
                                  height, SDL_WINDOW_BORDERLESS);
        if (!window) {
            std::cerr << "Error creating SDL window." << std::endl;
            return;
        }
        renderer = SDL_CreateRenderer(window, -1, 0);
        if (!renderer) {
            std::cerr << "Error creating SDL renderer." << std::endl;
            return;
        }

        gameIsRunning = true;

        fmt::print(projectile.toString());
    }

    void Game::processInput() {
        SDL_Event event;
        SDL_PollEvent(&event);

        switch (event.type) {
            case SDL_QUIT: {
                gameIsRunning = false;
                break;
            }
            case SDL_KEYDOWN: {
                if (event.key.keysym.sym == SDLK_ESCAPE) {
                    gameIsRunning = false;
                }
            }
            default: {
                break;
            }
        }
    }

    void Game::update(float deltaTime) {
        projectile.move(deltaTime);
    }

    void Game::render() {
        SDL_SetRenderDrawColor(renderer, 21, 21, 21, 255);
        SDL_RenderClear(renderer);

        SDL_Rect sdlProjectile = {(int)projectile.getX(), (int)projectile.getY(), 10, 10};

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderFillRect(renderer, &sdlProjectile);

        SDL_RenderPresent(renderer);
    }

    void Game::destroy() {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
    }

    void Game::runLoop() {
        while (isRunning()) {
            ticks.nextFrame();
            processInput();
            update(ticks.getDeltaTime());
            render();
        }
    }
}