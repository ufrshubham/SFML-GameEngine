#pragma once

#include <vector>
#include <memory>
#include <SFML/Graphics/Sprite.hpp>

#include "Game.hpp"

class Snake : public sf::Drawable
{
private:
	std::shared_ptr<Context> m_context;
	std::deque<sf::Sprite> m_body = std::deque<sf::Sprite>(4);
	sf::Vector2f m_direction;
	sf::Clock m_clock;
	bool m_grow = false;

public:
	Snake(std::shared_ptr<Context> context);
	~Snake();

	void Up();
	void Down();
	void Left();
	void Right();
	void Grow();
	bool OnWall();
	bool SelfIntersecting();
	bool IsHeadOnFood(float x, float y);

	void Init();
	void Move(sf::Time dt);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};
