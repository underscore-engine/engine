#include "Game/Game.hpp"

Game::Game(sf::RenderWindow& _window) :
	window { _window },
	player_view { sf::FloatRect(0, 0, window.getSize().x, window.getSize().y) },
	player { sf::Vector2f(500.f, 0.f), sf::Vector2f(215.f, 258.f) },
	platforms {
		StaticSprite("assets/platform.png", sf::Vector2f(10.f, 500.f), sf::Vector2f(760.f, 107.f)),
		StaticSprite("assets/platform.png", sf::Vector2f(1100.f, 720.f), sf::Vector2f(760.f, 107.f)),
		StaticSprite("assets/platform.png", sf::Vector2f(1100.f, 100.f), sf::Vector2f(760.f, 107.f))
	},
	enemies {
		Enemy(sf::Vector2f(0.f, 250.f), sf::Vector2f(215.f, 258.f)),
		Enemy(sf::Vector2f(1800.f, 670.f), sf::Vector2f(215.f, 258.f))
	}
{
	reset_positions(true);
}

void Game::reset_positions(bool hard_reset)
{
	player.setDetails(sf::Vector2f(500.f, 0.f), player.size);
	if (hard_reset)
	{
		enemies[0].setPosition(sf::Vector2f(0.f, 210.f));
		enemies[1].setPosition(sf::Vector2f(1800.f, 320.f));
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

void Game::update()
{
	player.updatePosition(platforms);

	for (unsigned int i = 0; i < 2; i++)
	{
		enemies[i].updatePosition(platforms, player.pos);
	}

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
	unsigned int i;
	for (i = 0; i < 2; i++)
	{
		enemies[i].draw(window);

		if (show_hitboxes)
			window.draw(enemies[i].get_hitbox_outline());
	}

	for (i = 0; i < 3; i++)
	{
		platforms[i].draw(window);

		if (show_hitboxes)
			window.draw(platforms[i].get_hitbox_outline());
	}

	player.draw(window);

	if (show_hitboxes)
		window.draw(player.get_hitbox_outline());

	window.draw(frame_tracker.text);
}