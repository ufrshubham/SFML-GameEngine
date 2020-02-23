#include <SFML/Window/Event.hpp>
#include "PauseState.hpp"

PauseState::PauseState(std::shared_ptr<Context> context) : m_context(context)
{
}

PauseState::~PauseState()
{
}

void PauseState::Init()
{
	m_pausedTitle.setFont(m_context->assets.GetFont("MainFont"));
	m_pausedTitle.setString("Press [Escape] to resume");
	m_pausedTitle.setOrigin(m_pausedTitle.getLocalBounds().width/2, m_pausedTitle.getLocalBounds().height / 2);
	m_pausedTitle.setPosition((float)m_context->window.getSize().x / 2, (float)m_context->window.getSize().y / 2);
}

void PauseState::ProcessInputs()
{
	sf::Event event;
	while (m_context->window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			m_context->window.close();
		}
		else if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::Escape)
			{
				m_context->states.PopLastState();
			}
		}
	}
}

void PauseState::Update(sf::Time dt)
{
}

void PauseState::Draw()
{
	m_context->window.draw(m_pausedTitle);
	m_context->window.display();
}
