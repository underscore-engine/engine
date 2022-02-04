#include "GameState.hpp"

GameState::GameState(sf::RenderWindow& window) :
	BaseState { window }
{
}

void GameState::handle_event(sf::Event& event)
{
	std::cout << event.key.code << std::endl;
}

void GameState::update()
{
}

void GameState::show()
{
}
