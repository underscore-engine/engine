#ifndef MenuState_H
#define MenuState_H

#include "Menu/Menu.hpp"
#include "State.hpp"

/**
 * The default state for the program which shows a menu with a few options.
 * Primarily there is a button to go to the main game.
 *
 * @param window A reference to the main window object
 */
class MenuState : BaseState
{
protected:
	Menu menu;

public:
	MenuState(sf::RenderWindow& window);

	void handle_event(sf::Event& event);
	void update(WindowStates& next_state);
	void show();
};

#endif
