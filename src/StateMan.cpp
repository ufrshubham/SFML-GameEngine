#include "StateMan.hpp"

Engine::StateMan::StateMan()
{
}

Engine::StateMan::~StateMan()
{
}

void Engine::StateMan::AddState(std::unique_ptr<State> newState, bool replace)
{
    m_add = true;
    m_replace = replace;

    // Actual state change should only happen in next game tick.
    // Store the new state for now, and process it in ProcessStateChange()
    m_newState = std::move(newState);
}

void Engine::StateMan::PopLastState()
{
    m_remove = true;
}

void Engine::StateMan::ProcessStateChange()
{
    // Because there should be something to pop!!!
    if (m_remove && (!m_states.empty()))
    {
        m_states.pop();

        if (!m_states.empty())
        {
            // If there is a state left, start it.
            m_states.top()->Start();
        }
        m_remove = false;
    }

    if (m_add)
    {
        if (m_replace)
        {
            // Pop only if there is a state to pop.
            if (!m_states.empty())
            {
                m_states.pop();
            }
            // After removing, pause any the top state if any.
            if (!m_states.empty())
            {
                // Pause the last state before adding a new one.
                m_states.top()->Pause();
            }
            m_replace = false;
        }

        // Add should always happen after replace has be processed.
        m_states.push(std::move(m_newState));

        // Init the new state.
        m_states.top()->Init();
        m_add = false;
    }
}

std::unique_ptr<Engine::State> &Engine::StateMan::GetCurrentState()
{
    return m_states.top();
}
