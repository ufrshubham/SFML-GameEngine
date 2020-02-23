#include "SplashState.hpp"
#include "MainMenuState.hpp"
#include <SFML/Window/Event.hpp>

SplashState::SplashState(std::shared_ptr<Context> context) : m_context(context)
{
}

SplashState::~SplashState()
{
}

void SplashState::Init()
{
    m_context->assets.AddFont("MainFont", "res/Kalam-Bold.ttf");

    m_title.setFont(m_context->assets.GetFont("MainFont"));
    m_title.setString("Subliminal Games");

    auto bounds = m_title.getLocalBounds();
    m_title.setOrigin(bounds.width / 2, bounds.height / 2);
    m_title.setPosition(m_context->window.getSize().x / 2.f, m_context->window.getSize().y / 2.f);
    m_title.setFillColor(sf::Color(255, 255, 255, 0));
}

void SplashState::ProcessInputs()
{
    sf::Event event;
    while (m_context->window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            m_context->window.close();
        }
    }
}

void SplashState::Update(sf::Time dt)
{
    double elapsedTime = m_clock.getElapsedTime().asSeconds();
    if (elapsedTime > 4.f)
    {
        //std::cout << "Time to go to Main Menu!!!" << std::endl;
        m_context->states.AddState(std::make_unique<MainMenuState>(MainMenuState(m_context)), true);
    }
    if(elapsedTime > 1.f)
    {
        // Just a clever way to have a fade in animation.
        m_title.setFillColor(sf::Color(255, 255, 255, std::clamp<int>((int)(elapsedTime * 255 / 2), 0, 255)));
    }
}

void SplashState::Draw()
{
    m_context->window.clear(sf::Color(0, 0, 0, 255));
    m_context->window.draw(m_title);
    m_context->window.display();
}