#include "State.hpp"

/**
 * This should handle all events that occur in the gameloop.
 * It will most commonly just hold a switch statement that points
 * to different functions of classes that the State contains.
 *
 * @param event A reference to the event to handle.
 */
void BaseState::handle_event(sf::Event& event)
{
	(void)event;
}

/**
 * This should handle all calculations and updates to sprites before showing them.
 * It should also run the logic to handle whether the WindowState changes. If it
 * does need to change, then use the passed in reference to `next_state` and change it
 * to the state to move to. By default it should always be WindowStates::NONE when passed in.
 *
 * @param next_state A reference to the next state variable. When changed the FSM changes states.
 */
void BaseState::update(WindowStates& next_state)
{
	(void)next_state;
}

/**
 * This should display all visuals to the screen. Use the `window` object passed
 * directly to the BaseState to draw it.
 *
 * Also do not include any `window.clear()` or `window.display()` here, as that is
 * done in main.py.
 */
void BaseState::show()
{}