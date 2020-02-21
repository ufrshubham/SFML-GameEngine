#pragma once

#include <map>
#include <string>
#include <memory>

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Font.hpp>

namespace Engine
{
// Holds all the Sprites and Fonts.
class AssetMan
{
private:
    std::map<std::string, std::shared_ptr<sf::Sprite>> m_sprites;
    std::map<std::string, std::shared_ptr<sf::Font>> m_fonts;

public:
    AssetMan();
    ~AssetMan();

    void AddSprite(const std::string& identifier, const std::string& filePath);
    void AddFont(const std::string& identifier, const std::string& filePath);

    std::shared_ptr<sf::Sprite> GetSprite(const std::string& identifier) const;
    std::shared_ptr<sf::Font> GetFont(const std::string& identifier) const;
};
} // namespace Engine
