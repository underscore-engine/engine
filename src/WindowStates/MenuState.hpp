#ifndef MenuState_H
#define MenuState_H

#include "Menu.hpp"
#include "State.hpp"

class MenuState : BaseState
{
protected:
	Menu menu;

public:
	MenuState(sf::RenderWindow& window);

	void handle_event(sf::Event& event);
	void update();
	void show();
};

#endif
