#include <SFML/Window/Event.hpp>

#include "MainMenuState.hpp"
#include "GamePlayState.hpp"

MainMenuState::MainMenuState(std::shared_ptr<Context> context) :
	m_context(context)
{
}

MainMenuState::~MainMenuState()
{
}

void MainMenuState::Init()
{
	m_playButton.setFont(m_context->assets.GetFont("MainFont"));
	m_exitButton.setFont(m_context->assets.GetFont("MainFont"));

	m_playButton.setString("Play");
	m_exitButton.setString("Exit");

	auto bounds = m_playButton.getLocalBounds();
	m_playButton.setOrigin(bounds.width / 2, bounds.height / 2);
	
	bounds = m_exitButton.getLocalBounds();
	m_exitButton.setOrigin(bounds.width / 2, bounds.height / 2);

	m_playButton.setPosition(m_context->window.getSize().x / 2.f, (m_context->window.getSize().y / 2.f) - 34.f);
	m_exitButton.setPosition(m_context->window.getSize().x / 2.f, (m_context->window.getSize().y / 2.f) + 34.f);
}

void MainMenuState::ProcessInputs()
{
	sf::Event event;
	while (m_context->window.pollEvent(event))
	{
		auto mousePos = sf::Mouse::getPosition(m_context->window);
		m_hoveringPlay = m_hoveringExit = false;
		m_playClicked = m_exitClicked = false;

		if (event.type == sf::Event::Closed)
		{
			m_context->window.close();
		}
		else if (event.type == sf::Event::MouseButtonPressed)
		{
			if (m_playButton.getGlobalBounds().contains((float)mousePos.x, (float)mousePos.y))
			{
				m_playClicked = true;
			}
			else if (m_exitButton.getGlobalBounds().contains((float)mousePos.x, (float)mousePos.y))
			{
				m_exitClicked = true;
			}
		}

		if (m_playButton.getGlobalBounds().contains((float)mousePos.x, (float)mousePos.y))
		{
			m_hoveringPlay = true;
		}
		else if (m_exitButton.getGlobalBounds().contains((float)mousePos.x, (float)mousePos.y))
		{
			m_hoveringExit = true;
		}
	}
}

void MainMenuState::Update(sf::Time dt)
{
	m_playButton.setFillColor(sf::Color::White);
	m_playButton.setScale(1.0f, 1.0f);

	m_exitButton.setFillColor(sf::Color::White);
	m_exitButton.setScale(1.0f, 1.0f);

	if (m_hoveringPlay)
	{
		m_playButton.setFillColor(sf::Color::Yellow);
		m_playButton.setScale(1.5f, 1.5f);

	}
	if (m_hoveringExit)
	{
		m_exitButton.setFillColor(sf::Color::Yellow);
		m_exitButton.setScale(1.5f, 1.5f);

	}
	if (m_playClicked)
	{
		m_context->states.AddState(std::make_unique<GamePlayState>(GamePlayState(m_context)));
	}
	if (m_exitClicked)
	{
		m_context->window.close();
	}
}

void MainMenuState::Draw()
{
	m_context->window.clear(sf::Color(0, 0, 0, 255));
	m_context->window.draw(m_playButton);
	m_context->window.draw(m_exitButton);
	m_context->window.display();
}
