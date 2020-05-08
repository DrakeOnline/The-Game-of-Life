#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "Cell.hpp"

namespace DrakeOnline {

    class Grid {
        public:
            // ======================CONSTRUCTORS=======================
            Grid(sf::RenderWindow&);
            // =====================PUBLIC METHODS======================
            void PrintGrid();
            // ====================PUBLIC VARIABLES=====================
            std::vector<std::vector<Cell>>  grid;
        private:
            // =====================PRIVATE METHODS=====================
            void CreateGrid();
            // ====================PRIVATE VARIABLES====================
            int                     _height;
            int                     _width;
            sf::RenderWindow&       _window;
    };

}
