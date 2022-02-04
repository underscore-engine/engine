#include "Enemy.hpp"
#include "FrameRate.hpp"
#include "Player.hpp"
#include "StaticSprite.hpp"
#include "WindowStates/GameState.hpp"
#include "WindowStates/MenuState.hpp"

sf::Clock deltatime_clock;
float deltatime = 0.f;

template <class T>
WindowStates MainStateLoop(T current_state, sf::RenderWindow& window)
{
	sf::Event event;
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

int main()
{
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Game");

	MenuState menu_state(window);
	GameState game_state(window);

	WindowStates current_state = WindowStates::MENU;
	while (window.isOpen())
	{
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

	return 0;
}
