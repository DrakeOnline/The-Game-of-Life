#pragma once

#include <SFML/Graphics.hpp>

namespace DrakeOnline {

    class Cell {
        public:
            // ======================CONSTRUCTORS=======================
            Cell();
            // ====================PUBLIC VARIABLES=====================
            bool                    alive;
            const int               size = 10;
            sf::RectangleShape      square;
    };

}
