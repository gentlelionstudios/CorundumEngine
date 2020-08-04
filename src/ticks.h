/*
 * Copyright (c) 2020 Gentle Lion Studios, Inc.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#pragma once

namespace corundum {
    class Ticks {
      public:
        Ticks() : ticksLastFrame {0}, deltaTime {0.0} {}
        ~Ticks() = default;

        void nextFrame();
        [[nodiscard]] float getDeltaTime() const;

      private:
        unsigned int ticksLastFrame;
        float deltaTime;
    };
}