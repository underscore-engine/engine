#include "GameState.hpp"

GameState::GameState(sf::RenderWindow& window) :
	BaseState { window },
	background_sprite { window },
	game(window)
{}

void GameState::handle_event(sf::Event& event)
{
	const bool control_down = sf::Keyboard::isKeyPressed(sf::Keyboard::LControl);

	switch (event.type)
	{
		case sf::Event::KeyPressed:
			game.handleKeyPress(event.key.code);

			if (control_down && event.key.code == sf::Keyboard::B)
				game.show_hitboxes = !game.show_hitboxes;

			else if (event.key.code == sf::Keyboard::R)
				game.reset_positions(control_down);

			break;

		case sf::Event::KeyReleased:
			game.handleKeyRelease(event.key.code);
			break;

		default:
			break;
	}
}

void GameState::update(WindowStates& next_state)
{
	game.update(next_state);
}

void GameState::show()
{
	background_sprite.draw(window, game.player_view);
	game.moveViewToPlayer();
	game.draw();
}
