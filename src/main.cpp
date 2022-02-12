#include "Enemy.hpp"
#include "FrameRate.hpp"
#include "Player.hpp"
#include "StaticSprite.hpp"
#include "WindowStates/GameState.hpp"
#include "WindowStates/MenuState.hpp"

sf::Clock deltatime_clock;
float deltatime = 0.f;

/**
 * This runs the main loop of each page. It takes in a certain WindowState class instance
 * and runs the game loop as long as the window remains open.
 *
 * When the state updates, it is able to change the `next_state` variable. When this changes
 * the game loop ends and the function returns the next state to move to.
 *
 * @tparam T This is dynamic type to act as a particular child of the BaseState class
 * @param current_state The state object that inherits from BaseState
 * @param window A reference to the RenderWindow object
 * @return WindowStates The next state/page to go to
 */
template <class T>
WindowStates MainStateLoop(T current_state, sf::RenderWindow& window)
{
	/**
	 * When the screen resizes, it runs the event sf::Event::Resized. However this causes deltatime
	 * to be much larger than it should be once it has resized, causing entities to clips through others.
	 * Therefore it records if it is resizing, and if so sets deltatime to 0 for next gameloop iteration.
	 */
	bool is_resizing = false;

	sf::Event event;
	// When next_state is NONE then do not leave current state
	WindowStates next_state = WindowStates::NONE;
	while (next_state == WindowStates::NONE && window.isOpen())
	{
		deltatime = deltatime_clock.restart().asSeconds() * 450.f;
		if (is_resizing)
		{
			deltatime = 0;
			is_resizing = false;
		}

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			else if (event.type == sf::Event::Resized)
			{
				is_resizing = true;
			}

			current_state.handle_event(event);
		}

		current_state.update(next_state);

		window.clear();
		current_state.show();
		window.display();
	}
	return next_state;
}

int main()
{
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Game");

	// Here define all states that can be moved to in the program
	MenuState menu_state(window);
	GameState game_state(window);

	// Begin the program in the MENU state
	WindowStates current_state = WindowStates::MENU;
	while (window.isOpen())
	{
		window.setView(window.getDefaultView());
		// Depending on WindowState run gameloop with correct class instance
		// Once gameloop ends, it will return the next state and then redo this switch
		// statement with the new state.
		switch (current_state)
		{
			case WindowStates::GAME:
				current_state = MainStateLoop(game_state, window);
				break;

			case WindowStates::MENU:
				current_state = MainStateLoop(menu_state, window);
				break;

			default:
				std::cout << "Error: Window State is not defined - Defaulting to menu" << std::endl;
				break;
		}
	}

	return 0;
}
