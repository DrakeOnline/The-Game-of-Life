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
            void CheckCells();
            void ChangeCells();
            void ProcessCells();
            void CalculateColor(Cell*);
            // ====================PUBLIC VARIABLES=====================
            std::vector<std::vector<Cell>>  grid;
            std::vector<Cell*>              cellsToChange;
        private:
            // =====================PRIVATE METHODS=====================
            void CreateGrid();
            // ====================PRIVATE VARIABLES====================
            int                     _height;
            int                     _width;
            sf::RenderWindow&       _window;
    };

}
