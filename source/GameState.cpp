
#include "./../include/GameState.hpp"
// #include <Windows.h>
#include <iostream>

namespace DrakeOnline {

    // ======================CONSTRUCTORS=======================
    GameState::GameState(GameDataRef data) : _data(data) {
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

        // Restart Game
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
            _data->machine.AddState(StateRef(new GameState(this->_data)));
        }
    }

    void GameState::Update(float deltaTime) {
        if(_clock.getElapsedTime().asSeconds() >= 0.1) {
            _data->grid.ProcessCells();
            _clock.restart();
        }

    }

    void GameState::Draw(float deltaTime) {
        // Clear, draw, then display
        _data->window.clear();
        _data->window.draw(_background);
        // Draw each cell
        for(int i = 0; i < _data->grid.cells.size(); i++) {
            for(int j = 0; j < _data->grid.cells[i].size(); j++) {
                _data->window.draw(_data->grid.cells[i][j].square);
            }
        }
        _data->window.display();
    }
}
