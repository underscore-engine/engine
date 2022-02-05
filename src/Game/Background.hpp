#ifndef Background_H
#define Background_H

#include "Sprite.hpp"

class Background : public Sprite
{
public:
	Background(sf::RenderWindow& _window);
	void draw(sf::RenderWindow& window, sf::View& view);
};

#endif
