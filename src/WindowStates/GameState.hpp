#ifndef GameState_H
#define GameState_H

#include "State.hpp"

class GameState : BaseState
{
private:
public:
	GameState(sf::RenderWindow& window);

	void handle_event(sf::Event& event);
	void update();
	void show();
};

#endif
