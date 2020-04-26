
#include <sstream>
#include <iostream>

#include "./../include/SplashState.hpp"

namespace DrakeOnline {
    // ======================CONSTRUCTORS=======================
    SplashState::SplashState(GameDataRef data) : _data(data) {}

    // =====================PUBLIC METHODS======================
    void SplashState::Initialize() {
        // Set sprite of background
        _data->assets.LoadTexture("Splash State Background",
                                  "resources/splash_screen.jpg");

        _background.setTexture(this->_data->assets.GetTexture("Splash State Background"));
    }

    void SplashState::HandleInput() {
        sf::Event event;

        // Check if window is closed
        while(_data->window.pollEvent(event)) {
            if (sf::Event::Closed == event.type) { _data->window.close(); }
        }
    }

    void SplashState::Update(float deltaTime) {
        // Change state after 2 seconds
        if (_clock.getElapsedTime().asSeconds() > 2.0f) {
            _data->window.close();
        }
    }

    void SplashState::Draw(float deltaTime) {
        // Clear, draw, then display
        _data->window.clear();
        _data->window.draw(_background);
        _data->window.display();
    }
}
