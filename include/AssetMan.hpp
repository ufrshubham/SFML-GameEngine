#pragma once

#include <map>
#include <string>
#include <memory>

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Font.hpp>

namespace Engine
{
// Holds all the Sprites and Fonts.
class AssetMan
{
private:
    std::map<std::string, sf::Texture> m_textures;
    std::map<std::string, sf::Font> m_fonts;

public:
    AssetMan();
    ~AssetMan();

    void AddSprite(const std::string &identifier, const std::string &filePath);
    void AddFont(const std::string &identifier, const std::string &filePath);

    sf::Texture &GetSprite(const std::string &identifier);
    sf::Font &GetFont(const std::string &identifier);
};
} // namespace Engine
