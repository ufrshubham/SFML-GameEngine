#pragma once

#include <stack>
#include <memory>

#include "State.hpp"

namespace Engine
{
// This class will hold all the game states->
// New states can be added, removed or replaced.
class StateMan
{
private:
    // LIFO.
    std::stack<std::unique_ptr<State>> m_states;
    std::unique_ptr<State> m_newState;

    bool m_add;
    bool m_remove;
    bool m_replace;

public:
    StateMan();
    ~StateMan();

    // Add your state to state stack using this. Set replace to true,
    // if you want the current state to get replaced with new state.
    void AddState(std::unique_ptr<State> newState, bool replace = false);

    // Pop off the current state.
    void PopLastState();

    // Actual state push pop happens here.
    void ProcessStateChange();

    std::unique_ptr<State> &GetCurrentState();
};
} // namespace Engine
