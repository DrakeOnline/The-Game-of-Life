
#include "./../include/GameState.hpp"
// #include <Windows.h>
#include <iostream>

namespace DrakeOnline {

    // ======================CONSTRUCTORS=======================
    GameState::GameState(GameDataRef data) : _data(data), _grid(_data->window) {
    }

    // =====================PUBLIC METHODS======================
    void GameState::Initialize() {
        // Set sprite of game background
        _data->assets.LoadTexture("Game State Background",
                                  "resources/images/game_background.jpg");

        _background.setTexture(this->_data->assets.GetTexture("Game State Background"));
    }

    void GameState::HandleInput() {
        sf::Event event;

        // Check if window is closed
        while(_data->window.pollEvent(event)) {
            if(sf::Event::Closed == event.type) { _data->window.close(); }
        }
    }

    void GameState::Update(float deltaTime) {

    }

    void GameState::Draw(float deltaTime) {
        // Clear, draw, then display
        _data->window.clear();
        _data->window.draw(_background);
        // Draw each cell
        for(int i = 0; i < _grid.grid.size(); i++) {
            for(int j = 0; j < _grid.grid[i].size(); j++) {
                _data->window.draw(_grid.grid[i][j].square);
            }
        }
        _data->window.display();
    }
}
