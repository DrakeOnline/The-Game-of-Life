
#include <cstdlib>
#include "./../include/Cell.hpp"

namespace DrakeOnline {

    // ======================CONSTRUCTORS=======================
    Cell::Cell() {
        // Set to either 0 or 1
        alive = rand() % 2;
        // Set square size
        square.setSize(sf::Vector2f(size, size));
        // Decide color based on alive or dead
        if (alive) { square.setFillColor(sf::Color::White); }
        else       { square.setFillColor(sf::Color::Black); }
        // Set origin to center of square
        square.setOrigin(size/2, size/2);
        // Initialize to 0,0
        square.setPosition(0, 0);
    }

}
