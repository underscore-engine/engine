#include "FrameRate.hpp"
#include "Hitbox.hpp"
#include "Player.hpp"
#include "StaticSprite.hpp"

int main()
{
	bool show_hitboxes = false;

	sf::RenderWindow window(sf::VideoMode(2000, 1500), "Game");

	Player player(sf::Vector2f(200.f, 50.f), sf::Vector2f());
	StaticSprite platforms[1] = { StaticSprite("assets/platform.png", sf::Vector2f(500.f, 500.f)) };

	FrameRateTracker frame_tracker;

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

		window.clear();

		for (unsigned int i = 0; i < 1; i++)
		{
			window.draw(platforms[i].sprite);
		}

		window.draw(player.sprite);

		if (show_hitboxes)
		{
			window.draw(player.get_hitbox_outline());

			for (unsigned int i = 0; i < 1; i++)
				window.draw(platforms[i].get_hitbox_outline());
		}

		frame_tracker.update();
		window.draw(frame_tracker.text);

		window.display();
	}

	return 0;
}
