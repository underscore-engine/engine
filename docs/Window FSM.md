# Window Finite State Machine

To make the game engine usable and scalable, there needed to be the option to split functionality into different pages and files, such as the menu and the game itself. Therefore a **finite state machine** (hereafter FSM) is needed to keep track of what state the program is currently in and to provide methods of transitioning from different states.

The primary logic for the FSM is held in the `main.cpp` file as it runs the main game loop and the high-level process of the program. This file has two main functions: **the gameloop** & **the stateloop**. Below shows some code for the gameloop:

```c++
template <class T>
WindowStates MainStateLoop(T current_state, sf::RenderWindow& window)
{
	sf::Event event;
	// When next_state is NONE then do not leave current state
	WindowStates next_state = WindowStates::NONE;
	while (next_state == WindowStates::NONE && window.isOpen())
	{
		deltatime = deltatime_clock.restart().asSeconds() * 450.f;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			current_state.handle_event(event);
		}

		current_state.update(next_state);

		window.clear();
		current_state.show();
		window.display();
	}
	return next_state;
};
```

The above code makes use of the `template <>` c++ feature which allows a function to take in an object of any type and just assume that it has the correct interface (functions). This means that states can do the same process even when represented as different classes such as the `GameState` and the `MenuState`.

The function then initialises some variables and begins the gameloop. It runs as long as the window is open or `next_state` is changed. `next_state` pretty much always takes the value of NONE, as that means that no state transitions should occur.

When `next_state` changes, we see that the gameloop will terminate and the new state will be returned by the function. Then it will move back to the state loop shown here:

```c++
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

		default:
			std::cout << "Error: Window State is not defined - Defaulting to menu" << std::endl;

		case WindowStates::MENU:
			current_state = MainStateLoop(menu_state, window);
			break;
	}
}
```

Here you can see the stateloop, which stays open as long as the window is open. It starts by resetting the window view, and then looks and the current state, which at the start is set the MENU.

Depending on the current state it will run the `MainStateLoop` function which holds the gameloop on a particular state object. Once the gameloop ends, it will return the new state and that will be set to current_state.
