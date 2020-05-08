
#include <cstdlib>
#include "./../include/Cell.hpp"

namespace DrakeOnline {

    // ======================CONSTRUCTORS=======================
    Cell::Cell() {
        alive = true;
        // Set square size
        square.setSize(sf::Vector2f(size, size));
        square.setFillColor(sf::Color((rand() % 256), (rand() % 256), (rand() % 256), 255));
        square.setOrigin(size/2, size/2);
        square.setPosition(0, 0);
    }

}
