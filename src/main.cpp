#include "Enemy.hpp"
#include "FrameRate.hpp"
#include "Player.hpp"
#include "StaticSprite.hpp"

float deltatime = 0.f;

int main()
{
	sf::Clock deltatime_clock;

	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Game");

	bool show_hitboxes = false;

	Player player(sf::Vector2f(500.f, 0.f), sf::Vector2f());

	StaticSprite platforms[2] = {
		StaticSprite("assets/platform.png", sf::Vector2f(10.f, 500.f)),
		StaticSprite("assets/platform.png", sf::Vector2f(1100.f, 720.f))
	};

	Enemy enemies[2] = {
		Enemy(sf::Vector2f(0.f, 210.f), sf::Vector2f(215.f, 258.f)),
		Enemy(sf::Vector2f(1800.f, 320.f), sf::Vector2f(215.f, 258.f))
	};

	FrameRateTracker frame_tracker;

	// Main Game Loop
	sf::Event event;
	while (window.isOpen())
	{
		deltatime = deltatime_clock.restart().asSeconds() * 450.f;

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

				case sf::Event::KeyReleased:
					player.handleKeyRelease(event.key.code);
					break;

				default:
					break;
			}
		}

		player.updatePosition(platforms);

		window.clear();

		for (int i = 0; i < 2; i++)
		{
			enemies[i].updatePosition(platforms, player.pos);

			window.draw(platforms[i].sprite);

			enemies[i].draw(window);
			window.draw(enemies[i].sprite);

			if (show_hitboxes)
			{
				window.draw(platforms[i].get_hitbox_outline());
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
