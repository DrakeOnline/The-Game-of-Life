
#include "./../include/AssetManager.hpp"


namespace DrakeOnline {
    // =====================PUBLIC METHODS======================
    void            AssetManager::LoadTexture(std::string name, std::string fileName) {
        // If loaded properly, add to map of textures
        sf::Texture texture;
        if(texture.loadFromFile(fileName)) { this->_textures[name] = texture; }
    }

    void            AssetManager::LoadFont(std::string name, std::string fileName) {
        // If loaded properly, add to map of _textures
        sf::Font font;
        if (font.loadFromFile(fileName)) { this->_fonts[name] = font; }
    }
    // Search for texture and return a reference to it
    sf::Texture&    AssetManager::GetTexture(std::string name) {
        return this->_textures.at(name);
    }
    // Search for font and return a reference to it
    sf::Font&       AssetManager::GetFont(std::string name) {
        return this->_fonts.at(name);
    }

}
