
#include "./../include/Grid.hpp"
#include <iostream>


namespace DrakeOnline {
    // ======================CONSTRUCTORS=======================
    Grid::Grid(sf::RenderWindow& window) : _window(window) {
        _width  = _window.getSize().x / 10;
        _height = _window.getSize().y / 10;
        CreateGrid();
    }

    // =====================PUBLIC METHODS======================
    void Grid::PrintGrid() {
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[i].size(); j++) {

                std::cout << grid[i][j].square.getPosition().x << ", " << grid[i][j].square.getPosition().y << '\t';
            }
            std::cout << std::endl;
        }
    }

    void Grid::CheckCells() {
    
        // Each row
        for(int i = 0; i < grid.size(); i++) {
            // Each column
            for(int j = 0; j < grid[i].size(); j++) {
                // Check what cells exist
                bool cellAbove  = i-1 >= 0;
                bool cellRight  = j+1 <  grid[i].size();
                bool cellBelow  = i+1 <  grid.size();
                bool cellLeft   = j-1 >= 0;
                // Count of alive neighbors
                int neighbors   = 0;


                // Check top
                if (cellAbove
                    && grid[i-1][j].alive)   { ++neighbors; }
                // Check top-right
                if (cellAbove
                    && cellRight
                    && grid[i-1][j+1].alive) { ++neighbors; }
                // Check right
                if (cellRight
                    && grid[i][j+1].alive)   { ++neighbors; }
                // Check bottom-right
                if (cellBelow
                    && cellRight
                    && grid[i+1][j+1].alive) { ++neighbors; }
                // Check bottom
                if (cellBelow
                    && grid[i+1][j].alive)   { ++neighbors; }
                // Check bottom-left
                if (cellBelow
                    && cellLeft
                    && grid[i+1][j-1].alive) { ++neighbors; }
                // Check left
                if (cellLeft
                    && grid[i][j-1].alive )  { ++neighbors; }
                // Check top-left
                if (cellLeft
                    && cellAbove
                    && grid[i-1][j-1].alive) { ++neighbors; }

                // Game of life rules
                // If cell is alive and has less than 2 neighbors it dies
                if(grid[i][j].alive && (neighbors < 2)) {
                    cellsToChange.push_back(&grid[i][j]);
                // If cell is alive and has more than 3 neighbors it dies
                } else if (grid[i][j].alive && (neighbors > 3)) {
                    cellsToChange.push_back(&grid[i][j]);
                // If cell is dead and has 2 neighbors it is now alive
                } else if((!grid[i][j].alive) && (neighbors == 3)) {
                    cellsToChange.push_back(&grid[i][j]);
                }

            }
        }
    }

    void Grid::ChangeCells() {
        for (int i = 0; i < cellsToChange.size(); i++) {
            // Change alive state
            cellsToChange[i]->alive = !cellsToChange[i]->alive;
            // Change color
            CalculateColor(cellsToChange[i]);
        }
        cellsToChange.clear();
    }

    void Grid::ProcessCells() {
        CheckCells();
        ChangeCells();
    }

    void Grid::CalculateColor (Cell* cell) {
        if (cell->alive) { cell->square.setFillColor(sf::Color::White); }
        else             { cell->square.setFillColor(sf::Color::Black); }
    }

    // =====================PRIVATE METHODS=====================
    void Grid::CreateGrid() {
        // Starting point for X and Y coordinates
        int currentXPosition    = 5;
        int currentYPosition    = 5;
        int XIncrement          = 10;
        int YIncrement          = 10;

        for(int row = 0; row < _height; row++) {
            // Reset X to "beginging" after every row
            currentXPosition = 5;
            // Add vector of cell to vector
            grid.push_back(std::vector<Cell>());

            for(int column = 0; column < _width; column++) {
                Cell cell;
                // Set cells coordinates to current X and Y and pushback onto vector
                cell.square.setPosition(currentXPosition, currentYPosition);
                grid[row].push_back(cell);
                // Increment the X coordinate
                currentXPosition += XIncrement;
            }
            // Increment the Y coordinate
            currentYPosition += YIncrement;
        }
    }

}
