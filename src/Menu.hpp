#ifndef Menu_H
#define Menu_H

#define max_number_of_items 3

class Menu
{
private:
	sf::Font font;
	sf::Text menu[max_number_of_items];
	bool selection[max_number_of_items];

public:
	Menu(float width, float height);

	void draw(sf::RenderWindow& window);
	void handleButtonPress(sf::Vector2i position_of_mouse);
	bool getSelection(int choice);
};

#endif