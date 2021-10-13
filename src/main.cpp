#include "Platform/Platform.hpp"

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

	sf::Texture texture;
	if (!texture.loadFromFile("main_character.png"))
	{
		// error...
	}
	sf::Sprite sprite;
	sprite.setTexture(texture);
	sprite.setPosition(sf::Vector2f(10.f, 50.f)); // absolute position

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
					sprite.move(sf::Vector2f(10.f, 0.f));
				}
				if (event.key.code == sf::Keyboard::A)
				{
					sprite.move(sf::Vector2f(-10.f, 0.f));
				}
				if (event.key.code == sf::Keyboard::S)
				{
					sprite.move(sf::Vector2f(0.f, 10.f));
				}
				if (event.key.code == sf::Keyboard::W)
				{
					sprite.move(sf::Vector2f(0.f, -10.f));
				}
			}
		}

		window.clear();
		window.draw(sprite);
		window.display();
	}

	return 0;
}
