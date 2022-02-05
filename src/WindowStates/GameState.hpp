#ifndef GameState_H
#define GameState_H

#include "Game/Background.hpp"
#include "Game/Game.hpp"
#include "State.hpp"

class GameState : BaseState
{
private:
	Background background_sprite;
	Game game;

public:
	GameState(sf::RenderWindow& window);

	void handle_event(sf::Event& event);
	void update(WindowStates& next_state);
	void show();
};

#endif
