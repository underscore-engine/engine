#include "Game/Background.hpp"

Background::Background(sf::RenderWindow& window) :
	Sprite { "assets/background-image.png", sf::Vector2f(0, 0), sf::Vector2f(window.getSize()) }
{}

/**
 * Calculates where to place the background based on the player view,
 * and draws it behind all other sprites.
 *
 * @param window A reference to the main window object
 * @param view A reference to the currently active player view
 */
void Background::draw(sf::RenderWindow& window, sf::View& view)
{
	const sf::Vector2f view_center = view.getCenter();
	const sf::Vector2f view_size = view.getSize();

	const sf::Vector2f left_top = sf::Vector2f(view_center.x - view_size.x / 2, view_center.y - view_size.y / 2);
	update_sprite(left_top, view_size);
	window.draw(sprite);
}