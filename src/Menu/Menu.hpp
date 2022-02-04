#ifndef Menu_H
#define Menu_H

#include "Menu/Button.hpp"

class Menu
{
private:
	MenuButton buttons[3] = {};

public:
	Menu(sf::Vector2u screen_size);

	void draw(sf::RenderWindow& window);
	void handleButtonPress(sf::Vector2i position_of_mouse);
	int hasButtonBeenPressed();
};

#endif