#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include "StateMan.hpp"
#include "AssetMan.hpp"

struct Context
{
    std::unique_ptr<Engine::AssetMan> assets;
    std::unique_ptr<Engine::StateMan> states;
    std::unique_ptr<sf::RenderWindow> window;

    Context()
    {
        assets = std::make_unique<Engine::AssetMan>();
        states = std::make_unique<Engine::StateMan>();
        window = std::make_unique<sf::RenderWindow>();
    }
};

class Game
{
    std::shared_ptr<Context> m_context;
    const sf::Time TimePerFrame = sf::seconds(1.f / 60.f);

public:
    Game(int width, int height, const std::string &title);
    ~Game();

    void Run();
};