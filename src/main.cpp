#include "Player.cpp"

int main()
{
	sf::RenderWindow window(sf::VideoMode(2000, 1500), "My window");

	Player player;

	sf::Event event;

	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::D)
				{
					player.move_right();
				}
				if (event.key.code == sf::Keyboard::A)
				{
					player.move_left();
				}
				if (event.key.code == sf::Keyboard::S)
				{
					player.move_down();
				}
				if (event.key.code == sf::Keyboard::W)
				{
					player.move_up();
				}
			}
		}

		window.clear();
		window.draw(player.sprite);
		window.display();
	}

	return 0;
}
