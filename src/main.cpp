#include "Player.cpp"

int main()
{
	sf::RenderWindow window(sf::VideoMode(2000, 1500), "Game");

	Player player;

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
		player.updatePosition();
		window.draw(player.sprite);
		window.display();
	}

	return 0;
}
