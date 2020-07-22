
#include "./../include/Grid.hpp"
#include <iostream>


namespace DrakeOnline {
    // ======================CONSTRUCTORS=======================
    Grid::Grid() {
        // Fix: Hardcoded sizing
        _width  = 1280 / 10;
        _height = 720 / 10;
        CreateGrid();
    }

    // =====================PUBLIC METHODS======================
    void Grid::PrintGrid() {
        for(int i = 0; i < cells.size(); i++) {
            for(int j = 0; j < cells[i].size(); j++) {

                std::cout << cells[i][j].square.getPosition().x << ", " << cells[i][j].square.getPosition().y << '\t';
            }
            std::cout << std::endl;
        }
    }

    void Grid::CheckCells() {

        // Each row
        for(int i = 0; i < cells.size(); i++) {
            // Each column
            for(int j = 0; j < cells[i].size(); j++) {
                // Check what cells exist
                bool cellAbove  = i-1 >= 0;
                bool cellRight  = j+1 <  cells[i].size();
                bool cellBelow  = i+1 <  cells.size();
                bool cellLeft   = j-1 >= 0;
                // Count of alive neighbors
                int neighbors   = 0;


                // Check top
                if (cellAbove
                    && cells[i-1][j].alive)   { ++neighbors; }
                // Check top-right
                if (cellAbove
                    && cellRight
                    && cells[i-1][j+1].alive) { ++neighbors; }
                // Check right
                if (cellRight
                    && cells[i][j+1].alive)   { ++neighbors; }
                // Check bottom-right
                if (cellBelow
                    && cellRight
                    && cells[i+1][j+1].alive) { ++neighbors; }
                // Check bottom
                if (cellBelow
                    && cells[i+1][j].alive)   { ++neighbors; }
                // Check bottom-left
                if (cellBelow
                    && cellLeft
                    && cells[i+1][j-1].alive) { ++neighbors; }
                // Check left
                if (cellLeft
                    && cells[i][j-1].alive )  { ++neighbors; }
                // Check top-left
                if (cellLeft
                    && cellAbove
                    && cells[i-1][j-1].alive) { ++neighbors; }

                // Game of life rules
                // If cell is alive and has less than 2 neighbors it dies
                if(cells[i][j].alive && (neighbors < 2)) {
                    cellsToChange.push_back(&cells[i][j]);
                // If cell is alive and has more than 3 neighbors it dies
            } else if (cells[i][j].alive && (neighbors > 3)) {
                    cellsToChange.push_back(&cells[i][j]);
                // If cell is dead and has 2 neighbors it is now alive
            } else if((!cells[i][j].alive) && (neighbors == 3)) {
                    cellsToChange.push_back(&cells[i][j]);
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
            cells.push_back(std::vector<Cell>());

            for(int column = 0; column < _width; column++) {
                Cell cell;
                // Set cells coordinates to current X and Y and pushback onto vector
                cell.square.setPosition(currentXPosition, currentYPosition);
                cells[row].push_back(cell);
                // Increment the X coordinate
                currentXPosition += XIncrement;
            }
            // Increment the Y coordinate
            currentYPosition += YIncrement;
        }
    }

}
