#ifndef Background_H
#define Background_H

#include "Sprite.hpp"

/**
 * A sprite that draws a static image to the background during the game.
 * It takes into account the moving window view and adjusts the background position to
 * account for it.
 *
 * @param window A reference to the window
 */
class Background : public Sprite
{
public:
	Background(sf::RenderWindow& _window);
	void draw(sf::RenderWindow& window, sf::View& view);
};

#endif
