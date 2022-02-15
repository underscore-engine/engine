#include "Game/Game.hpp"

/**
 * Initialise all objects and classes inside the game
 */
Game::Game(sf::RenderWindow& _window) :
	window { _window },
	player { sf::Vector2f(500.f, 0.f), sf::Vector2f(215.f, 258.f) },
	platforms {
		new StaticSprite("assets/platform.png", sf::Vector2f(10.f, 500.f), sf::Vector2f(760.f, 107.f)),
		new StaticSprite("assets/platform.png", sf::Vector2f(1100.f, 100.f), sf::Vector2f(760.f, 107.f)),
		new StaticSprite("assets/platform.png", sf::Vector2f(2100.f, 500.f), sf::Vector2f(760.f, 107.f))
	},
	enemies {
		new Enemy(sf::Vector2f(0.f, -100.f), sf::Vector2f(215.f, 258.f)),
		new Enemy(sf::Vector2f(2700.f, -100.f), sf::Vector2f(215.f, 258.f))
	},
	player_view { sf::FloatRect(0, 0, window.getSize().x, window.getSize().y) }
{
	reset_positions(true);
}

/**
 * Resets the positions of the player (and possibly enemies)
 *
 * @param hard_reset Whether to reset enemies as well
 */
void Game::reset_positions(bool hard_reset)
{
	player.setDetails(sf::Vector2f(500.f, 0.f), player.size);
	if (hard_reset)
	{
		enemies[0]->setPosition(sf::Vector2f(0.f, 250.f));
		enemies[1]->setPosition(sf::Vector2f(2700.f, 250.f));
	}
}

void Game::handleKeyPress(sf::Keyboard::Key key_code)
{
	player.handleKeyPress(key_code);
}

void Game::handleKeyRelease(sf::Keyboard::Key key_code)
{
	player.handleKeyRelease(key_code);
}

void Game::update(WindowStates& next_state)
{
	if (player.health < 0)
	{
		// If the player has died, go to Menu screen (TODO: implement GameOver screen)
		next_state = WindowStates::MENU;
		return;
	}

	player.updatePosition(platforms);

	for (Enemy* enemy : enemies)
	{
		enemy->updatePosition(platforms, player.pos);
		player.handleCollide(*enemy);
	}

	player.updateHealth();

	// Update information in frame_tracker text widget
	frame_tracker.add_info("Vel", std::to_string(player.vel.x).substr(0, 4) + "  |  " + std::to_string(player.vel.y).substr(0, 4));
	frame_tracker.update();
}

void Game::moveViewToPlayer()
{
	player_view.setCenter(sf::Vector2f(player.pos.x, 300));
	window.setView(player_view);
}

void Game::draw()
{
	for (Enemy* enemy : enemies)
	{
		enemy->draw(window);

		if (show_hitboxes)
			window.draw(enemy->get_hitbox_outline());
	}

	for (StaticSprite* platform : platforms)
	{
		platform->draw(window);

		if (show_hitboxes)
			window.draw(platform->get_hitbox_outline());
	}

	player.draw(window);

	if (show_hitboxes)
		window.draw(player.get_hitbox_outline());

	window.draw(frame_tracker.text);
	window.draw(player.health_display);
}