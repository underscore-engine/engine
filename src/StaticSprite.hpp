#ifndef StaticSprite_H
#define StaticSprite_H

#include "Hitbox.hpp"

/**
 * A class for objects such as obsticles and platforms that will
 * never move and will not be affected by forces, but can still
 * be interacted with using its hitbox.
 *
 * @param texture_name The path to the image for the sprite texture
 * @param _pos The initial position for the top left of the sprite
 */
class StaticSprite : public Hitbox
{
private:
	sf::Texture texture;

public:
	sf::Sprite sprite;
	StaticSprite(std::string texture_name, sf::Vector2f _pos);
};

#endif