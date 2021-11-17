#include "Enemy.hpp"
#include "FrameRate.hpp"
#include "Menu.hpp"
#include "Player.hpp"
#include "StaticSprite.hpp"

float deltatime = 0.f;

int main()
{
	sf::Clock deltatime_clock;

	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Game");

	// Setup our view (camera)
	sf::View player_view(sf::FloatRect(0, 0, window.getSize().x, window.getSize().y));

	Menu menu(window.getSize().x, window.getSize().y);

	sf::Event event;
	//menu loop
	// while (window.isOpen())
	// {
	// 	//waits for player to make a choice

	// 	while (window.pollEvent(event))
	// 	{
	// 		switch (event.type)
	// 		{
	// 			case sf::Event::Closed:
	// 				window.close();
	// 				break;
	// 			case sf::Event::MouseButtonPressed:
	// 				menu.handleButtonPress(sf::Mouse::getPosition());
	// 				break;
	// 			default:
	// 				break;
	// 		}
	// 	}

	// 	if (menu.getSelection(0))
	// 	{
	// 		break;
	// 	}
	// 	else if (menu.getSelection(2))
	// 	{
	// 		window.close();
	// 	}

	// 	window.clear();

	// 	menu.draw(window);
	// 	window.display();
	// }

	bool show_hitboxes = false;

	Player player(sf::Vector2f(500.f, 0.f), sf::Vector2f());

	StaticSprite platforms[3] = {
		StaticSprite("assets/platform.png", sf::Vector2f(10.f, 500.f)),
		StaticSprite("assets/platform.png", sf::Vector2f(1100.f, 720.f)),
		StaticSprite("assets/platform.png", sf::Vector2f(1100.f, 100.f))
	};

	Enemy enemies[2] = {
		Enemy(sf::Vector2f(0.f, 250.f), sf::Vector2f()),
		Enemy(sf::Vector2f(1800.f, 670.f), sf::Vector2f())
	};

	FrameRateTracker frame_tracker;

	// Main Game Loop
	while (window.isOpen())
	{
		deltatime = deltatime_clock.restart().asSeconds() * 450.f;
		// we keep our view centered on the player
		player_view.setCenter(player.pos);
		window.setView(player_view);

		while (window.pollEvent(event))
		{
			switch (event.type)
			{
				case sf::Event::Closed:
					window.close();
					break;

				case sf::Event::KeyPressed:
					player.handleKeyPress(event.key.code);

					if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) && event.key.code == sf::Keyboard::B)
						show_hitboxes = !show_hitboxes;

					else if (event.key.code == sf::Keyboard::R)
						player.pos = sf::Vector2f(500.f, 0.f);
					break;

				case sf::Event::MouseButtonPressed:
					//
					break;

				case sf::Event::KeyReleased:
					player.handleKeyRelease(event.key.code);
					break;

				default:
					break;
			}
		}

		player.updatePosition(platforms);

		window.clear();

		// Render the platforms
		for (int i = 0; i < 3; i++)
		{
			window.draw(platforms[i].sprite);

			if (show_hitboxes)
			{
				window.draw(platforms[i].get_hitbox_outline());
			}
		}

		// Render the enemies
		for (int i = 0; i < 2; i++)
		{
			enemies[i].updatePosition(platforms, player.pos);

			window.draw(enemies[i].sprite);

			if (show_hitboxes)
			{
				window.draw(enemies[i].get_hitbox_outline());
			}
		}

		window.draw(player.sprite);
		if (show_hitboxes)
			window.draw(player.get_hitbox_outline());

		frame_tracker.add_info("Vel", std::to_string(player.vel.x).substr(0, 4) + "  |  " + std::to_string(player.vel.y).substr(0, 4));
		frame_tracker.update();
		window.draw(frame_tracker.text);

		window.display();
	}

	return 0;
}
