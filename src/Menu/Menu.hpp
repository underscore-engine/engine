#ifndef Menu_H
#define Menu_H

#include "Menu/Button.hpp"

/**
 * This handle the main functionality of the Menu by containing each of the buttons
 * and collating the information for each of them.
 *
 * @param screen_size This is the vector containing the size in pixels of the screen
 */
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