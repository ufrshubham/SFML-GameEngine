#pragma once

#include "Game.hpp"
#include "State.hpp"
#include <SFML/Graphics/Text.hpp>

class PauseState : public Engine::State
{
private:
	std::shared_ptr<Context> m_context;
	sf::Text m_pausedTitle;

public:
	PauseState(std::shared_ptr<Context> context);
	~PauseState();

	void Init() override;
	void ProcessInputs() override;
	void Update(sf::Time dt) override;
	void Draw() override;
};
