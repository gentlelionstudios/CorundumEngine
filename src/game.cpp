/*
 * Copyright (c) 2020 Gentle Lion Studios, Inc.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include "game.h"
#include <iostream>

namespace corundum {
    float projectilePosX = 0.0f;
    float projectilePosY = 0.0f;
    float projectileVelX = 0.1f;
    float projectileVelY = 0.1f;

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

    void Game::update() {
        projectilePosX += projectileVelX;
        projectilePosY += projectileVelY;
    }

    void Game::render() {
        SDL_SetRenderDrawColor(renderer, 21, 21, 21, 255);
        SDL_RenderClear(renderer);

        SDL_Rect projectile = {(int)projectilePosX, (int)projectilePosY, 10, 10};

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderFillRect(renderer, &projectile);

        SDL_RenderPresent(renderer);
    }

    void Game::destroy() {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
    }
}