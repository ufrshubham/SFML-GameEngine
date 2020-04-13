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
    std::map<std::string, std::unique_ptr<sf::Texture>> m_textures;
    std::map<std::string, std::unique_ptr<sf::Font>> m_fonts;

public:
    AssetMan();
    ~AssetMan();

    void AddTexture(const std::string &identifier, const std::string &filePath, bool repeated = false);
    void AddFont(const std::string &identifier, const std::string &filePath);

    const sf::Texture &GetTexture(const std::string &identifier);
    const sf::Font &GetFont(const std::string &identifier);
};
} // namespace Engine
