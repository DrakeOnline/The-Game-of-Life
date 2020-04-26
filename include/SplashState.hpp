#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"


namespace DrakeOnline {

    class SplashState : public State {
        public:
            // ======================CONSTRUCTORS=======================
            SplashState(GameDataRef);
            // =====================PUBLIC METHODS======================
            void Initialize();
            void HandleInput();
            void Update(float);
            void Draw(float);
        private:
            // ====================PRIVATE VARIABLES====================
            GameDataRef     _data;
            sf::Clock       _clock;
            sf::Sprite      _background;
    };

}
