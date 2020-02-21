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
    void Init(){};

    // Handle all the player inputs here.
    void ProcessInputs(){};

    // Make changes to your game state depending on the processed inputs here.
    void Update(sf::Time delta){};

    // Draw all your drawables here.
    void Draw(){};

    // Pause this state.
    virtual void Pause() = 0;
    
    // Start this state.
    virtual void Start() = 0;
};
} // namespace Engine