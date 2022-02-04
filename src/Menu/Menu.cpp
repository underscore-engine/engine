#include "Menu/Menu.hpp"

Menu::Menu(sf::Vector2u screen_size)
{
	const sf::Vector2f button_size = sf::Vector2f(600, 299);
	float x_line = screen_size.x / 2 - button_size.x / 2;

	buttons[0].set_details("Play", sf::Vector2f(x_line, screen_size.y / 4 * 1 - button_size.y / 2 - 50), button_size);
	buttons[1].set_details("Options", sf::Vector2f(x_line, screen_size.y / 4 * 2 - button_size.y / 2), button_size);
	buttons[2].set_details("Exit", sf::Vector2f(x_line, screen_size.y / 4 * 3 - button_size.y / 2 + 50), button_size);
}

void Menu::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < 3; i++)
		buttons[i].draw(window);
}

void Menu::handleButtonPress(sf::Vector2i position_of_mouse)
{
	for (int i = 0; i < 3; i++)
		buttons[i].handleButtonPress(position_of_mouse);
}

int Menu::hasButtonBeenPressed()
{
	for (int i = 0; i < 3; i++)
	{
		if (buttons[i].hasBeenPressed())
			return i;
	}

	return -1;
}
