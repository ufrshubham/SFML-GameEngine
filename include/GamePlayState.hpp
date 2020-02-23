#pragma once

#include <array>
#include <SFML/Graphics/Sprite.hpp>
#include "Game.hpp"
#include "State.hpp"
#include "Snake.hpp"

class GamePlayState : public Engine::State
{
private:
	std::shared_ptr<Context> m_context;
	sf::Sprite m_grass;
	std::array<sf::Sprite, 4> m_walls;
	bool m_paused = false;
	Snake m_snake;

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
