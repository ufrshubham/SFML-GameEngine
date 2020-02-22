#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include "StateMan.hpp"
#include "AssetMan.hpp"

struct Context
{
    Engine::AssetMan assets;
    Engine::StateMan states;
    sf::RenderWindow window;
};

class Game
{
    std::shared_ptr<Context> m_context = std::make_shared<Context>();
    const sf::Time TimePerFrame = sf::seconds(1.f / 60.f);

public:
    Game(int width, int height, const std::string &title);
    ~Game();

    void Run();
};