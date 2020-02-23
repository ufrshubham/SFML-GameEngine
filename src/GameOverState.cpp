#include <SFML/Window/Event.hpp>
#include "GameOverState.hpp"
#include "GamePlayState.hpp"
#include "MainMenuState.hpp"

GameOverState::GameOverState(std::shared_ptr<Context> context) : m_context(context)
{
}

GameOverState::~GameOverState()
{
}

void GameOverState::Init()
{
	m_gameOverTitle.setFont(m_context->assets.GetFont("MainFont"));
	m_retryButton.setFont(m_context->assets.GetFont("MainFont"));
	m_homeButton.setFont(m_context->assets.GetFont("MainFont"));

	m_gameOverTitle.setString("Game Over!!!");
	m_gameOverTitle.setCharacterSize(40);

	m_retryButton.setString("Retry");
	m_homeButton.setString("Main Menu");

	m_gameOverTitle.setOrigin(m_gameOverTitle.getLocalBounds().width / 2, m_gameOverTitle.getLocalBounds().height / 2);
	m_gameOverTitle.setPosition((float)m_context->window.getSize().x / 2, (float)m_context->window.getSize().y / 2 - 100.f);

	m_retryButton.setOrigin(m_retryButton.getLocalBounds().width / 2, m_retryButton.getLocalBounds().height / 2);
	m_retryButton.setPosition((float)m_context->window.getSize().x / 2, (float)m_context->window.getSize().y / 2 - 30.f);

	m_homeButton.setOrigin(m_homeButton.getLocalBounds().width / 2, m_homeButton.getLocalBounds().height / 2);
	m_homeButton.setPosition((float)m_context->window.getSize().x / 2, (float)m_context->window.getSize().y / 2 + 30.f);
}

void GameOverState::ProcessInputs()
{
	sf::Event event;
	while (m_context->window.pollEvent(event))
	{
		auto mousePos = sf::Mouse::getPosition(m_context->window);
		m_hoveringRetry = m_hoveringHome = false;
		m_retryClicked = m_homeClicked = false;

		if (event.type == sf::Event::Closed)
		{
			m_context->window.close();
		}
		else if (event.type == sf::Event::MouseButtonPressed)
		{
			if (m_retryButton.getGlobalBounds().contains((float)mousePos.x, (float)mousePos.y))
			{
				m_retryClicked = true;
			}
			else if (m_homeButton.getGlobalBounds().contains((float)mousePos.x, (float)mousePos.y))
			{
				m_homeClicked = true;
			}
		}

		if (m_retryButton.getGlobalBounds().contains((float)mousePos.x, (float)mousePos.y))
		{
			m_hoveringRetry = true;
		}
		else if (m_homeButton.getGlobalBounds().contains((float)mousePos.x, (float)mousePos.y))
		{
			m_hoveringHome = true;
		}
	}
}

void GameOverState::Update(sf::Time dt)
{
	m_retryButton.setFillColor(sf::Color::White);
	m_retryButton.setScale(1.0f, 1.0f);

	m_homeButton.setFillColor(sf::Color::White);
	m_homeButton.setScale(1.0f, 1.0f);

	if (m_hoveringRetry)
	{
		m_retryButton.setFillColor(sf::Color::Yellow);
		m_retryButton.setScale(1.5f, 1.5f);

	}
	if (m_hoveringHome)
	{
		m_homeButton.setFillColor(sf::Color::Yellow);
		m_homeButton.setScale(1.5f, 1.5f);

	}
	if (m_retryClicked)
	{
		m_context->states.AddState(std::make_unique<GamePlayState>(GamePlayState(m_context)));
	}
	if (m_homeClicked)
	{
		m_context->states.AddState(std::make_unique<MainMenuState>(MainMenuState(m_context)));
	}
}

void GameOverState::Draw()
{
	m_context->window.clear(sf::Color(255, 0, 0, 255));
	m_context->window.draw(m_gameOverTitle);
	m_context->window.draw(m_retryButton);
	m_context->window.draw(m_homeButton);
	m_context->window.display();
}
