#include "Menu.hpp"

Menu::Menu(float current_width, float current_height) :
	MenuButton {}
{
	width = current_width;
	height = current_height;

	//creates menu options
	for (int i = 0; i < max_number_of_items; i++)
	{
		menuItems[i] = MenuButton();
		selection[i] = false;
	}
}

void Menu::draw(sf::RenderWindow& window, float new_width, float new_height)
{
	//draws the menu options
	sf::Texture texture;

	for (int i = 0; i < max_number_of_items; i++)
	{
		switch (i)
		{
			case 0:
				texture.loadFromFile("assets/play.png");
				break;
			default:
				texture.loadFromFile("assets/QuitButton.png");
		}

		menuItems[i].width = texture.getSize().x * menuItems[i].scale;
		menuItems[i].height = texture.getSize().y * menuItems[i].scale;

		menuItems[i].setPosition((width / 2 - menuItems[i].width / 2), (height / (max_number_of_items + 1) * (i + 1)), new_width / width, new_height / height);
		menuItems[i].sprite.setTexture(texture);

		window.draw(menuItems[i].sprite);
	}
}

void Menu::handleButtonPress(float pos_mouse_x, float pos_mouse_y)
{
	//find where the mouse is clicking

	for (int i = 0; i < max_number_of_items; i++)
	{

		if ((pos_mouse_x > menuItems[i].position.x) and (pos_mouse_x < menuItems[i].position.x + menuItems[i].width * menuItems[i].window_scale_x))
		{
			if ((pos_mouse_y > menuItems[i].position.y) and (pos_mouse_y < menuItems[i].position.y + menuItems[i].height * menuItems[i].window_scale_y))
			{
				selection[i] = true;
			}
		}
	}
}

bool Menu::getSelection(int choice)
{
	return selection[choice];
}