#include "MenuButton.hpp"

MenuButton::MenuButton()
{
	scale = 0.5f;
	sprite.setScale(scale, scale);
}

void MenuButton::setPosition(float width, float height, float x, float y)
{
	window_scale_x = x;
	window_scale_y = y;

	position = sf::Vector2f(width * window_scale_x, height * window_scale_y);
	sprite.setPosition(width, height);
}
