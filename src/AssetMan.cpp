#include "AssetMan.hpp"

Engine::AssetMan::AssetMan()
{
}

Engine::AssetMan::~AssetMan()
{
}

void Engine::AssetMan::AddTexture(const std::string &identifier, const std::string &filePath, bool repeated)
{
    auto texture = std::make_unique<sf::Texture>();

    if (texture->loadFromFile(filePath))
    {
        texture->setRepeated(repeated);
        m_textures[identifier] = std::move(texture);
    }
}

void Engine::AssetMan::AddFont(const std::string &identifier, const std::string &filePath)
{
    auto font = std::make_unique<sf::Font>();

    if (font->loadFromFile(filePath))
    {
        m_fonts[identifier] = std::move(font);
    }
}

const sf::Texture &Engine::AssetMan::GetTexture(const std::string &identifier)
{
    return *(m_textures.at(identifier).get());
}

const sf::Font &Engine::AssetMan::GetFont(const std::string &identifier)
{
    return *(m_fonts.at(identifier).get());
}
