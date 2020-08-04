/*
 * Copyright (c) 2020 Gentle Lion Studios, Inc.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include "ticks.h"
#include <SDL2/SDL_timer.h>

namespace corundum {
    unsigned int const FRAMES_PER_SECOND = 60;
    unsigned int const TARGET_FRAME_TIME = 1000 / FRAMES_PER_SECOND;

    void Ticks::nextFrame() {
        // Implement frame limiting to ensure the frame rate matches the target rate
        unsigned int timeToWait = TARGET_FRAME_TIME - (SDL_GetTicks() - ticksLastFrame);
        if (timeToWait > 0 && timeToWait <= TARGET_FRAME_TIME) {
            SDL_Delay(timeToWait);
        }

        // Delta time is the difference in milliseconds from the last frame
        // (converted to seconds)
        deltaTime = (SDL_GetTicks() - ticksLastFrame) / 1000.0f;

        // Clamp deltaTime
        if (deltaTime > 0.05f) {
            deltaTime = 0.05f;
        }

        // Update the tick counts for the next frame
        ticksLastFrame = SDL_GetTicks();
    }

    float Ticks::getDeltaTime() const {
        return deltaTime;
    }
}