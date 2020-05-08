#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"
#include "Grid.hpp"


namespace DrakeOnline {

    class GameState : public State {
        public:
            // ======================CONSTRUCTORS=======================
            GameState(GameDataRef);
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
            Grid            _grid;
    };

}
