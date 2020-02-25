#include "Snake.hpp"

Snake::Snake(std::shared_ptr<Context> context) : m_context(context), m_direction(32.f, 0.f)
{
}

Snake::~Snake()
{
}

void Snake::Up()
{
	sf::Vector2f up = sf::Vector2f(0.f, -32.f);
	
	if (m_direction != -up)
	{
		m_direction = up;
	}
}

void Snake::Down()
{
	sf::Vector2f down = sf::Vector2f(0.f, 32.f);
	if (m_direction != -down)
	{
		m_direction = down;
	}
}

void Snake::Left()
{
	sf::Vector2f left = sf::Vector2f(-32.f, 0.f);
	if (m_direction != -left)
	{
		m_direction = left;
	}
}

void Snake::Right()
{
	sf::Vector2f right = sf::Vector2f(32.f, 0.f);
	if (m_direction != -right)
	{
		m_direction = right;
	}
}

void Snake::Grow()
{
	m_grow = true;
}

bool Snake::OnWall()
{
	bool isOnWall = false;

	if ((m_body.back().getPosition().x < m_body.back().getTexture()->getSize().x) || 
		(m_body.back().getPosition().x > m_context->window.getSize().x - 2 * m_body.back().getTexture()->getSize().x))
	{
		isOnWall = true;
	}
	else if ((m_body.back().getPosition().y < m_body.back().getTexture()->getSize().y) || 
		(m_body.back().getPosition().y > m_context->window.getSize().y - 2 * m_body.back().getTexture()->getSize().y))
	{
		isOnWall = true;
	}
	return isOnWall;
}

bool Snake::SelfIntersecting()
{
	bool isIntersecting = false;

	for (int i = 0; i < m_body.size() - 1; ++i)
	{
		if (m_body.back().getGlobalBounds().intersects(m_body[i].getGlobalBounds()))
		{
			isIntersecting = true;
		}
	}

	return isIntersecting;
}

bool Snake::IsHeadOnFood(float x, float y)
{
	bool isOnFood = false;

	if (m_body.back().getGlobalBounds().contains(x, y))
	{
		isOnFood = true;
	}

	return isOnFood;
}

void Snake::Init()
{
	m_context->assets.AddTexture("Snake", "res/Snake.png");
	float x = 32.f;
	float y = 32.f;

	for (auto& i : m_body)
	{
		i.setTexture(m_context->assets.GetTexture("Snake"));
		i.setPosition(x, y);
		x += 32.f;
	}
}

void Snake::Move(sf::Time dt)
{
	double elapsedTime = m_clock.getElapsedTime().asSeconds();

	if (elapsedTime > 0.1)
	{
		sf::Sprite newSprite;
		newSprite.setTexture(m_context->assets.GetTexture("Snake"));
		newSprite.setPosition(m_body.back().getPosition() + m_direction);

		if (!m_grow)
		{
			m_body.pop_front();
		}
		else
		{
			m_grow = false;
		}

		m_body.push_back(newSprite);
		m_clock.restart();
	}
}

void Snake::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (auto& i : m_body)
	{
		target.draw(i);
	}
}
