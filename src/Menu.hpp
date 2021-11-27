#define max_number_of_items 2
#include "MenuButton.hpp"

class Menu : public MenuButton
{
private:
	sf::Font font;
	MenuButton menuItems[max_number_of_items];
	bool selection[max_number_of_items];
	float width;
	float height;
	float screen_width;
	float screen_height;

public:
	Menu(float current_width, float current_height);
	void draw(sf::RenderWindow& window, float new_width, float new_height);
	void handleButtonPress(float pos_mouse_x, float pos_mouse_y);
	bool getSelection(int choice);
};
