#pragma once

#include <array>
#include <random>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "Game.hpp"
#include "State.hpp"
#include "Snake.hpp"

class GamePlayState : public Engine::State
{
private:
	std::shared_ptr<Context> m_context;
	
	Snake m_snake;
	sf::Sprite m_grass;
	sf::Sprite m_food;
	sf::Text m_scoreText;
	int m_score = 0;
	
	std::array<sf::Sprite, 4> m_walls;
	
	bool m_paused = false;
	bool m_foodEaten = false;

	std::default_random_engine m_generator;
	std::uniform_int_distribution<int> m_distributorX;
	std::uniform_int_distribution<int> m_distributorY;

public:
	GamePlayState(std::shared_ptr<Context> context);
	~GamePlayState();

	void Init() override;
	void ProcessInputs() override;
	void Update(sf::Time dt) override;
	void Draw() override;

	void Pause() override;
	void Start() override;
};
