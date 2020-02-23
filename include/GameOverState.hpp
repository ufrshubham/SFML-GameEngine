#pragma once

#include "Game.hpp"
#include "State.hpp"
#include <SFML/Graphics/Text.hpp>

class GameOverState : public Engine::State
{
private:
	std::shared_ptr<Context> m_context;
	sf::Text m_gameOverTitle;
	sf::Text m_retryButton;
	sf::Text m_homeButton;

	bool m_hoveringRetry = false;
	bool m_hoveringHome = false;

	bool m_retryClicked = false;
	bool m_homeClicked = false;

public:
	GameOverState(std::shared_ptr<Context> context);
	~GameOverState();

	void Init() override;
	void ProcessInputs() override;
	void Update(sf::Time dt) override;
	void Draw() override;
};
