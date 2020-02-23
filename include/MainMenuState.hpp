#pragma once

#include <memory>
#include <SFML/Graphics/Text.hpp>
#include "State.hpp"
#include "Game.hpp"

class MainMenuState : public Engine::State
{
private:
	std::shared_ptr<Context> m_context;
	sf::Text m_playButton;
	sf::Text m_exitButton;

	bool m_hoveringPlay = false;
	bool m_hoveringExit = false;

	bool m_playClicked = false;
	bool m_exitClicked = false;

public:
	MainMenuState(std::shared_ptr<Context> context);
	~MainMenuState();

	void Init() override;
	void ProcessInputs() override;
	void Update(sf::Time dt) override;
	void Draw() override;
};
