#pragma once

#include <SFML/System/Time.hpp>

namespace Engine
{
// Base class for all the game states.
// States can be like splash screen state, main menu state,
// pause menu state, game over state, etc.
class State
{

public:
    State(){};
    virtual ~State(){};

    // Initilize everything here just to keep constructor clean.
    virtual void Init() = 0;

    // Handle all the player inputs here.
    virtual void ProcessInputs() = 0;

    // Make changes to your game state depending on the processed inputs here.
    virtual void Update(sf::Time delta) = 0;

    // Draw all your drawables here.
    virtual void Draw() = 0;

    // Pause this state.
    virtual void Pause();
    
    // Start this state.
    virtual void Start();
};
} // namespace Engine