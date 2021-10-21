#include "Enemy.hpp"
#include "FrameRate.hpp"
#include "Hitbox.hpp"
#include "Player.hpp"
#include "StaticSprite.hpp"

int main()
{
	bool show_hitboxes = false;

	sf::RenderWindow window(sf::VideoMode(2000, 1500), "Game");

	Player player(sf::Vector2f(800.f, 730.f), sf::Vector2f());
	StaticSprite platforms[2] = { StaticSprite("assets/platform.png", sf::Vector2f(100.f, 1000.f)),
		StaticSprite("assets/platform.png", sf::Vector2f(1100.f, 1000.f)) };
	Enemy enemies[2] = { Enemy(sf::Vector2f(1800.f, 730.f), sf::Vector2f()),
		Enemy(sf::Vector2f(200.f, 730.f), sf::Vector2f()) };

	FrameRateTracker frame_tracker;

	// Main Game Loop
	sf::Event event;
	while (window.isOpen())
	{
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
					{
						show_hitboxes = !show_hitboxes;
					}
					break;

				case sf::Event::KeyReleased:
					player.handleKeyRelease(event.key.code);
					break;

				default:
					break;
			}
		}

		player.updatePosition(platforms);
		for (int i = 0; i < 2; i++)
		{
			enemies[i].updatePosition(platforms, player.pos);
		}

		window.clear();

		for (int i = 0; i < 2; i++)
		{
			window.draw(platforms[i].sprite);
			window.draw(enemies[i].sprite);
		}

		window.draw(player.sprite);

		if (show_hitboxes)
		{
			window.draw(player.get_hitbox_outline());

			for (unsigned int i = 0; i < 2; i++)
				window.draw(platforms[i].get_hitbox_outline());
		}

		frame_tracker.update();
		window.draw(frame_tracker.text);

		window.display();
	}

	return 0;
}
