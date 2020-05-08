
#include "./../include/Grid.hpp"
#include <iostream>


namespace DrakeOnline {
    // ======================CONSTRUCTORS=======================
    Grid::Grid(sf::RenderWindow& window) : _window(window) {
        _width  = _window.getSize().x / 10;
        _height = _window.getSize().y / 10;
        CreateGrid();
        PrintGrid();
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
