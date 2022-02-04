#include "State.hpp"

void BaseState::handle_event(sf::Event& event)
{
	(void)event;
}

void BaseState::update(WindowStates& next_state)
{
	(void)next_state;
}

void BaseState::show()
{
}