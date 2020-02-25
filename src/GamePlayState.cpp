#include <iostream>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "GamePlayState.hpp"
#include "PauseState.hpp"
#include "GameOverState.hpp"

GamePlayState::GamePlayState(std::shared_ptr<Context> context) :
	m_context(context), m_snake(context), m_generator((unsigned)time(nullptr)), m_distributorX(32, context->window.getSize().x - 2 * 32), 
	m_distributorY(32, context->window.getSize().y - 2 * 32)
{
}

GamePlayState::~GamePlayState()
{
}

void GamePlayState::Init()
{
	m_context->assets.AddTexture("Grass","res/Grass.png", true);
	m_context->assets.AddTexture("Wall","res/Wall.png", true);
	m_context->assets.AddTexture("Food", "res/Food.png");
	
	m_grass.setTexture(m_context->assets.GetTexture("Grass"));
	m_grass.setTextureRect({ 0, 0, (int)m_context->window.getSize().x,  (int)m_context->window.getSize().y });

	m_scoreText.setFont(m_context->assets.GetFont("MainFont"));
	m_scoreText.setFillColor(sf::Color(0,0,0,255));
	m_scoreText.setString("Score : 0");
	m_scoreText.setPosition(34.f, 0.2f);

	for (int i = 0; i < 2; ++i)
	{
		m_walls[i].setTexture(m_context->assets.GetTexture("Wall"));
		m_walls[i].setTextureRect({ 0, 0, (int)m_context->window.getSize().x,  (int)m_walls[i].getTexture()->getSize().y });

	}
	for (int i = 2; i < 4; ++i)
	{
		m_walls[i].setTexture(m_context->assets.GetTexture("Wall"));
		m_walls[i].setTextureRect({ 0, 0, (int)m_walls[i].getTexture()->getSize().x,  (int)m_context->window.getSize().y });

	}
	m_walls[1].setPosition(0.f, (float)(m_context->window.getSize().y - m_walls[1].getTexture()->getSize().y));
	m_walls[3].setPosition((float)(m_context->window.getSize().x - m_walls[3].getTexture()->getSize().x), 0.f);

	m_food.setTexture(m_context->assets.GetTexture("Food"));

	int x = m_distributorX(m_generator);
	int y = m_distributorY(m_generator);

	x = std::clamp<int>(x + x % 32, 32, m_context->window.getSize().x - 2*32);
	y = std::clamp<int>(y + y % 32, 32, m_context->window.getSize().y - 2*32);

	m_food.setPosition((float)x, (float)y);

	m_snake.Init();
}

void GamePlayState::ProcessInputs()
{
	if (!m_paused)
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
				switch (event.key.code)
				{
				case sf::Keyboard::Escape:
					m_paused = true;
					m_context->states.AddState(std::make_unique<PauseState>(PauseState(m_context)));
					break;
				case sf::Keyboard::Up:
					m_snake.Up();
					break;
				case sf::Keyboard::Down:
					m_snake.Down();
					break;
				case sf::Keyboard::Left:
					m_snake.Left();
					break;
				case sf::Keyboard::Right:
					m_snake.Right();
					break;
				default:
					break;
				}
			}
		}

		if (m_snake.OnWall() || m_snake.SelfIntersecting())
		{
			m_paused = true;
			m_context->states.AddState(std::make_unique<GameOverState>(GameOverState(m_context)));
		}

		if (m_snake.IsHeadOnFood(m_food.getPosition().x + m_food.getLocalBounds().width / 2,
			m_food.getPosition().y + m_food.getLocalBounds().height / 2))
		{
			m_score += 10;
			m_foodEaten = true;
		}
	}
}

void GamePlayState::Update(sf::Time dt)
{
	if (!m_paused)
	{
		m_snake.Move(dt);
	}
	if (m_foodEaten)
	{
		int x = m_distributorX(m_generator);
		int y = m_distributorY(m_generator);

		x = std::clamp<int>(x + x % 32, 32, m_context->window.getSize().x - 2*32);
		y = std::clamp<int>(y + y % 32, 32, m_context->window.getSize().y - 2*32);

		m_food.setPosition((float)x, (float)y);
		m_snake.Grow();
		m_scoreText.setString("Score : " + std::to_string(m_score));
		m_foodEaten = false;
	}
}

void GamePlayState::Draw()
{
	m_context->window.clear();
	m_context->window.draw(m_grass);

	for (auto wall : m_walls)
	{
		m_context->window.draw(wall);
	}

	m_context->window.draw(m_food);
	m_context->window.draw(m_snake);
	m_context->window.draw(m_scoreText);
	m_context->window.display();
}

void GamePlayState::Pause()
{
	m_paused = true;
}

void GamePlayState::Start()
{
	m_paused = false;
}
