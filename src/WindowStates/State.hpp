#ifndef BaseState_H
#define BaseState_H

enum WindowStates
{
	NONE,
	MENU,
	GAME,
};

/**
 * The base state for the finite state machine that defines what
 * is shown on the window. It should be inherited by other classes.
 */
class BaseState
{
protected:
	sf::RenderWindow& window;

public:
	BaseState(sf::RenderWindow& _window) :
		window { _window }
	{}

	void handle_event(sf::Event& event);
	void update(WindowStates& next_state);
	void show();
};

#endif
