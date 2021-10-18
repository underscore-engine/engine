#include "Hitbox.hpp"
#include "Player.hpp"
#include "StaticSprite.hpp"

int main()
{
	sf::RenderWindow window(sf::VideoMode(2000, 1500), "Game");

	Player player(sf::Vector2f(200.f, 50.f), sf::Vector2f());
	StaticSprite platforms[1] = { StaticSprite("assets/platform.png", sf::Vector2f(500.f, 500.f)) };

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
					break;

				case sf::Event::KeyReleased:
					player.handleKeyRelease(event.key.code);
					break;

				default:
					break;
			}
		}

		window.clear();

		for (int i = 0; i < 1; i++)
		{
			window.draw(platforms[i].sprite);
		}

		player.updatePosition(platforms);
		window.draw(player.sprite);

		window.display();
	}

	return 0;
}
