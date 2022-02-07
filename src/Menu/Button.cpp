#include "Menu/Button.hpp"

MenuButton::MenuButton(std::string _text, sf::Vector2f _pos, sf::Vector2f _size) :
	Sprite { "assets/button-background.png", _pos, _size }
{
	has_been_selected = false;

	font.loadFromFile("assets/opensans.ttf");
	text_sprite = sf::Text(text, font);
	text_sprite.setCharacterSize(100);
	text_sprite.setFillColor(sf::Color::Black);
	set_details(_text, _pos, _size);
}

MenuButton::MenuButton() :
	Sprite { "assets/button-background.png", sf::Vector2f(), sf::Vector2f() }
{
	has_been_selected = false;

	font.loadFromFile("assets/opensans.ttf");
	text_sprite = sf::Text("", font);
	text_sprite.setCharacterSize(100);
	text_sprite.setFillColor(sf::Color::Black);
}

/**
 * Takes in the parameters for the button and applies them.
 * Automatically positions text in center of button.
 *
 * @param _text The text inside the button
 * @param _pos The position of the top left coordinate of the button sprite
 * @param _size The size of the button sprite
 */
void MenuButton::set_details(std::string _text, sf::Vector2f _pos, sf::Vector2f _size)
{
	text = _text;
	pos = _pos;
	size = _size;

	text_sprite.setString(_text);

	const sf::FloatRect tsize = text_sprite.getLocalBounds();
	text_sprite.setPosition(sf::Vector2f(
		pos.x + size.x / 2 - tsize.width / 2 - 5,
		pos.y + size.y / 2 - tsize.height / 2 - 15));

	update_sprite(_pos, _size);
};

void MenuButton::draw(sf::RenderWindow& window)
{
	window.draw(sprite);
	window.draw(text_sprite);
}

/**
 * If the click occured inside the button, record it and return it when asked
 *
 * @param position_of_mouse The vector for mouse position
 */
void MenuButton::handleButtonPress(sf::Vector2i position_of_mouse)
{
	has_been_selected = true;

	if (position_of_mouse.x < pos.x || (pos.x + size.x) < position_of_mouse.x)
	{
		has_been_selected = false;
	}

	else if (position_of_mouse.y < pos.y || (pos.y + size.y) < position_of_mouse.y)
	{
		has_been_selected = false;
	}
}

/**
 * All buttons will be asked whether they were clicked at the same time.
 * Therefore this will return whether it was clicked during any of the events.
 * If it was clicked, then it will reset its attribute (to prevent multiple perceived mouse clicks)
 * and return true. Else it will return false.
 *
 * @return bool Whether the button has been clicked
 */
bool MenuButton::hasBeenPressed()
{
	if (has_been_selected)
	{
		has_been_selected = false;
		return true;
	}
	return false;
}