#pragma once

#include <memory>
#include <SFML/Graphics/Text.hpp>
#include "Game.hpp"
#include "State.hpp"

class SplashState : public Engine::State
{
    std::shared_ptr<Context> m_context;
    sf::Text m_title;
    sf::Clock m_clock;

public:
    SplashState(std::shared_ptr<Context> context);
    ~SplashState();

    void Init() override;
    void ProcessInputs() override;
    void Update(sf::Time dt) override;
    void Draw() override;
};