#pragma once

#include <SFML/Graphics.hpp>


namespace DrakeOnline {

    class InputManager {
        public:
            // =====================PUBLIC METHODS======================
            bool            IsSpriteClicked(sf::Sprite,
                                            sf::Mouse::Button,
                                            sf::RenderWindow&);
            sf::Vector2i    GetMousePosition(sf::RenderWindow&);
    };

}
