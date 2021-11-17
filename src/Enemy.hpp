#ifndef Enemy_H
#define Enemy_H

#include "Hitbox.hpp"
#include "Sprite.hpp"
#include "StaticSprite.hpp"

/**
 * The main enemy class
 *
 * @param pos The initial position
 * @param size The width and height of the enemy's hitbox
 */
class Enemy : public Hitbox, public Sprite
{
private:
	sf::Texture texture;

public:
	Enemy(sf::Vector2f pos, sf::Vector2f size);

	// Updates the position of the sprite
	void updatePosition(StaticSprite* platforms, sf::Vector2f player_pos);
};

#endif
