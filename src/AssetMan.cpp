#include "AssetMan.hpp"

Engine::AssetMan::AssetMan()
{
}

Engine::AssetMan::~AssetMan()
{
}

void Engine::AssetMan::AddTexture(const std::string &identifier, const std::string &filePath, bool repeated)
{
    sf::Texture texture;
    if (texture.loadFromFile(filePath))
    {
        texture.setRepeated(repeated);
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

sf::Texture &Engine::AssetMan::GetTexture(const std::string &identifier)
{
    return m_textures.at(identifier);
}

sf::Font &Engine::AssetMan::GetFont(const std::string &identifier)
{
    return m_fonts.at(identifier);
}
