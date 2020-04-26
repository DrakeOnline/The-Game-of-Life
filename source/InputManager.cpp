#include "./../include/InputManager.hpp"

namespace DrakeOnline {

    bool IsSpriteClicked(sf::Sprite object,
                         sf::Mouse::Button button,
                         sf::RenderWindow& window) {
        // Check if button is pressed
        if(sf::Mouse::isButtonPressed(button)) {
            sf::IntRect tempRect(object.getPosition().x,
                                 object.getPosition().y,
                                 object.getGlobalBounds().width,
                                 object.getGlobalBounds().height);

            // return if mouse is also in bounds of object
            return tempRect.contains(sf::Mouse::getPosition(window));
        } else {
            return false;
        }
    }

    sf::Vector2i InputManager::GetMousePosition(sf::RenderWindow& window) {
        return sf::Mouse::getPosition(window);
    }

}
