#include "AssetMan.hpp"

Engine::AssetMan::AssetMan()
{
}

Engine::AssetMan::~AssetMan()
{
}

void Engine::AssetMan::AddTexture(const std::string &identifier, const std::string &filePath)
{
    sf::Texture texture;
    if (texture.loadFromFile(filePath))
    {
        m_textures[identifier] = texture;
    }
}

void Engine::AssetMan::AddFont(const std::string &identifier, const std::string &filePath)
{
    sf::Font font;
    if (font.loadFromFile(filePath))
    {
        m_fonts[identifier] = font;
    }
}

sf::Texture &Engine::AssetMan::GetSprite(const std::string &identifier)
{
    return m_textures.at(identifier);
}

sf::Font &Engine::AssetMan::GetFont(const std::string &identifier)
{
    return m_fonts.at(identifier);
}
