/*
 * Copyright (c) 2020 Gentle Lion Studios, Inc.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include "constants.h"
#include "game.h"

int main(int argc, char *args[]) {
    auto game = corundum::Game{};

    game.initialize(corundum::WINDOW_WIDTH, corundum::WINDOW_HEIGHT);

    while (game.isRunning()) {
        game.processInput();
        game.update();
        game.render();
    }

    game.destroy();

    return 0;
}

