#include "Game.hpp"
#include "SplashState.hpp"

Game::Game(int width, int height, const std::string &title)
{
    m_context->window.create(sf::VideoMode(width, height), title);
    m_context->states.AddState(std::make_unique<SplashState>(SplashState(m_context)));
}

Game::~Game()
{
}

void Game::Run()
{
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;

    while (m_context->window.isOpen())
    {
        m_context->states.ProcessStateChange();
        timeSinceLastUpdate += clock.restart();
        while (timeSinceLastUpdate > TimePerFrame)
        {
            timeSinceLastUpdate -= TimePerFrame;
            m_context->states.ProcessStateChange();
            m_context->states.GetCurrentState()->ProcessInputs();
            m_context->states.GetCurrentState()->Update(TimePerFrame);
        }
        m_context->states.GetCurrentState()->Draw();
    }
}