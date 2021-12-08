#include "State.hpp"

void BaseState::handle_event(sf::Event& event)
{
	std::cout << event.key.code << std::endl;
}

void BaseState::update()
{
}

void BaseState::show()
{
}