#include "Menu.hpp"

Menu::Menu(float width, float height)
{
	//creates menu options

	font.loadFromFile("assets/opensans.ttf");

	for (int i = 0; i < max_number_of_items; i++)
	{
		menu[i] = sf::Text("0 fps", font);
		menu[i].setCharacterSize(100);
		menu[i].setFillColor(sf::Color::Red);

		switch (i)
		{
			case 0:
				menu[i].setString("Play");
				break;
			case 1:
				menu[i].setString("Options");
				break;
			default:
				menu[i].setString("Exit");
		}

		selection[i] = false;

		float text_width = menu[i].getLocalBounds().width;

		menu[i].setPosition(sf::Vector2f((width / 2) - (text_width / 2), height / (max_number_of_items + 1) * (i + 1)));
	}
}

void Menu::draw(sf::RenderWindow& window)
{
	//draws the menu options
	for (int i = 0; i < max_number_of_items; i++)
	{
		window.draw(menu[i]);
	}
}

void Menu::handleButtonPress(sf::Vector2i position_of_mouse)
{
	//find where the mouse is clicking
	//this needs to be made dynamic as it only works with the exact window size
	for (int i = 0; i < max_number_of_items; i++)
	{
		if ((position_of_mouse.x > menu[i].getPosition().x + 550) and position_of_mouse.x < menu[i].getPosition().x + 550 + menu[i].getLocalBounds().width)
		{
			if ((position_of_mouse.y > menu[i].getPosition().y + 550) and (position_of_mouse.y < menu[i].getPosition().y + 550 + menu[i].getLocalBounds().height))
			{
				menu[i].setFillColor(sf::Color::White);
				selection[i] = true;
			}
		}
	}
}

bool Menu::getSelection(int choice)
{
	return selection[choice];
}