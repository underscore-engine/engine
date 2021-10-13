#include "Platform/Platform.hpp"
#include "Player.cpp"

int main()
{
	util::Platform platform;

#if defined(_DEBUG)
	std::cout << "Hello World!" << std::endl;
#endif

	sf::RenderWindow window;
	// in Windows at least, this must be called before creating the window
	float screenScalingFactor = platform.getScreenScalingFactor(window.getSystemHandle());
	// Use the screenScalingFactor
	window.create(sf::VideoMode(1000.0f * screenScalingFactor, 1000.0f * screenScalingFactor), "SFML works!");
	platform.setIcon(window.getSystemHandle());

	sf::Event event;

	Player player;

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
