#include "AssetMan.hpp"

Engine::AssetMan::AssetMan()
{
}

Engine::AssetMan::~AssetMan()
{
}

void Engine::AssetMan::AddSprite(const std::string& identifier, const std::string& filePath)
{
    sf::Sprite sprite;
    sf::Texture texture;

    texture.loadFromFile(filePath);
    sprite.setTexture(texture);

    m_sprites[identifier] = std::make_shared<sf::Sprite>(sprite);
}

void Engine::AssetMan::AddFont(const std::string& identifier, const std::string& filePath)
{
    sf::Font font;
    font.loadFromFile(filePath);

    m_fonts[identifier] = std::make_shared<sf::Font>(font);
}

std::shared_ptr<sf::Sprite> Engine::AssetMan::GetSprite(const std::string& identifier) const
{
    return m_sprites.at(identifier);
}

std::shared_ptr<sf::Font> Engine::AssetMan::GetFont(const std::string& identifier) const
{
    return m_fonts.at(identifier);
}
