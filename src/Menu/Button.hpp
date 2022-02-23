#ifndef MenuButton_H
#define MenuButton_H

#include "Sprite.hpp"

/**
 * This defines a button that does not move, has a background rectangular image,
 * and contains centred variable text.
 *
 * Once clicked the button records it and returns true once asked.
 *
 * While the class can be initialised through the constructor, the default constructor
 * can also be used if calculations are needed. Then just use the `set_details` method.
 */
class MenuButton : Sprite
{
private:
	sf::Font font;
	sf::Text text_sprite;

	std::string text;
	bool has_been_selected;

public:
	sf::Vector2f pos;
	sf::Vector2f size;
	MenuButton(std::string text, sf::Vector2f start_pos, sf::Vector2f target_size);
	MenuButton();

	void set_details(std::string text, sf::Vector2f start_pos, sf::Vector2f target_size);
	void draw(sf::RenderWindow& window);
	void handleButtonPress(sf::Vector2i position_of_mouse);
	bool hasBeenPressed();
};

#endif