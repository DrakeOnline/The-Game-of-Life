#pragma once

#include <memory>
#include <string>
#include <SFML/Graphics.hpp>
#include "StateMachine.hpp"
#include "AssetManager.hpp"
#include "InputManager.hpp"
#include "Grid.hpp"


namespace DrakeOnline {

    struct GameData {
        StateMachine        machine;
        sf::RenderWindow    window;
        AssetManager        assets;
        InputManager        input;
        Grid                grid;
    };

    typedef std::shared_ptr<GameData> GameDataRef;

    class Game {
        public:
            // ======================CONSTRUCTORS=======================
            Game(int, int, std::string);
        private:
            // ====================PRIVATE VARIABLES====================
            const float     deltaTime = 1.0f/60.0f;
            sf::Clock       _clock;
            GameDataRef     _data = std::make_shared<GameData>();
            // =====================PRIVATE METHODS=====================
            void            Run();
    };

}
