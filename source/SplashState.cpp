
#include <sstream>
#include <iostream>
#include "./../include/SplashState.hpp"
// #include "./../include/GameState.hpp"

namespace DrakeOnline {
    // ======================CONSTRUCTORS=======================
    SplashState::SplashState(GameDataRef data) : _data(data) {}

    // =====================PUBLIC METHODS======================
    void SplashState::Initialize() {
        // Set sprite of background
        _data->assets.LoadTexture("Splash State Background",
                                  "resources/images/splash_screen.jpg");

        _background.setTexture(this->_data->assets.GetTexture("Splash State Background"));
        _background.setColor(sf::Color(0, 0, 0, 0));
    }

    void SplashState::HandleInput() {
        sf::Event event;

        // Check if window is closed
        while(_data->window.pollEvent(event)) {
            if (sf::Event::Closed == event.type) { _data->window.close(); }
        }
    }

    void SplashState::Update(float deltaTime) {
        static bool dissapearing    = false;
        static int transparency     = 0;

        // Intro done, go to next game state
        if (dissapearing && transparency == 0 ) { _data->window.close(); }

        // Once it hits full transparency, start the dissapearing process
        if (transparency == 255) { dissapearing = true; }

        // Fast and small changes
        if (_clock.getElapsedTime().asSeconds() >= 0.002f) {

            // Dissapear faster than it appears
            if (dissapearing) { transparency-=5; }
            else { transparency++; }

            // Set new transparency and restart clock
            _background.setColor(sf::Color(255, 255, 255, transparency));
            _clock.restart();
        }
    }

    void SplashState::Draw(float deltaTime) {
        // Clear, draw, then display
        _data->window.clear();
        _data->window.draw(_background);
        _data->window.display();
    }
}
