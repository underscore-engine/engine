#ifndef StaticSprite_H
#define StaticSprite_H

#include "Hitbox.hpp"
#include "Sprite.hpp"

/**
 * A class for objects such as obsticles and platforms that will
 * never move and will not be affected by forces, but can still
 * be interacted with using its hitbox.
 *
 * @param texture_name The path to the image for the sprite texture
 * @param pos The initial position for the top left of the sprite
 * @param target_size The size that the platform should be
 */
class StaticSprite : public Hitbox, public Sprite
{
public:
	StaticSprite(std::string texture_name, sf::Vector2f pos, sf::Vector2f target_size);
};

#endif