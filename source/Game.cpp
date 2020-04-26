#include "./../include/Game.hpp"
#include "./../include/SplashState.hpp"

#include <stdlib.h>
#include <time.h>

namespace DrakeOnline {
    // ======================CONSTRUCTORS=======================
    Game::Game(int width, int height, std::string title) {
        // Set random seed to the current computer time
        srand(int(time(NULL)));

        // Create a window with SFML
        _data->window.create(sf::VideoMode(width, height),
                            title,
                            sf::Style::Close | sf::Style::Titlebar);

        // Add the splash state to our state machine so it starts there
        _data->machine.AddState(StateRef(new SplashState(this->_data)));

        this->Run();
    }

    // =====================PRIVATE METHODS=====================
    void Game::Run() {
        // For calculating delta time
        float newTime, frameTime, interpolation;

        float currentTime   = this->_clock.getElapsedTime().asSeconds();
        float accumulator   = 0.0f;

        // Open window
        while(this->_data->window.isOpen()) {
            this->_data->machine.ProcessStateChanges();

            // Get how long it took to run state processing
            newTime     = this->_clock.getElapsedTime().asSeconds();
            frameTime   = newTime - currentTime;

            // A limit for frameTime
            if(frameTime > 0.25f) { frameTime = 0.25f; }

            currentTime = newTime;
            accumulator += frameTime;

            // Run updates and input checks until accumulator lowered to deltaTime
            while(accumulator >= deltaTime) {
                this->_data->machine.GetActiveState()->HandleInput();
                this->_data->machine.GetActiveState()->Update(deltaTime);

                accumulator -= deltaTime;
            }

            // get the amount of times the previous while loop ran
            interpolation = accumulator/deltaTime;

            this->_data->machine.GetActiveState()->Draw(interpolation);

        }
    }
}
