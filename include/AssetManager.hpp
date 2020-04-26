#pragma once

#include <map>
#include <SFML/Graphics.hpp>

namespace DrakeOnline {

    class AssetManager {
        public:
            // ======================CONSTRUCTORS=======================
            AssetManager() {}
            ~AssetManager() {}
            // =====================PUBLIC METHODS======================
            void            LoadTexture(std::string, std::string);
            void            LoadFont(std::string, std::string);
            sf::Texture&    GetTexture(std::string);
            sf::Font&       GetFont(std::string);
        private:
            // ====================PRIVATE VARIABLES====================
            std::map<std::string, sf::Texture>  _textures;
            std::map<std::string, sf::Font>     _fonts;
    };

}
