#include "FrameRate.hpp"
// #include "Hitbox.hpp"
#include "Player.hpp"
#include "StaticSprite.hpp"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Game");

	bool show_hitboxes = false;

	Player player(sf::Vector2f(500.f, 0.f), sf::Vector2f());
	StaticSprite platforms[2] = { StaticSprite("assets/platform.png", sf::Vector2f(10.f, 500.f)),
		StaticSprite("assets/platform.png", sf::Vector2f(1100.f, 720.f)) };

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
			window.draw(platforms[i].sprite);
		}

		window.draw(player.sprite);

		if (show_hitboxes)
		{
			window.draw(player.get_hitbox_outline());

			for (unsigned int i = 0; i < 2; i++)
				window.draw(platforms[i].get_hitbox_outline());
		}

		frame_tracker.update(std::to_string(player.vel.y));
		window.draw(frame_tracker.text);

		window.display();
	}

	return 0;
}
