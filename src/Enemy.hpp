// enemy header file

#ifndef Enemy_H
#define Enemy_H

#include "Hitbox.hpp"
#include "StaticSprite.hpp"

/**
 * The main enemy class
 *
 * @param _pos The initial position
 * @param _size The width and height of the enemy's hitbox
 */
class Enemy : public Hitbox
{
private:
	sf::Texture texture;
	float speed;

public:
	sf::Sprite sprite;
	Enemy(sf::Vector2f _pos, sf::Vector2f _size);

	sf::Vector2f calculateVelocity();

	// Updates the position of the sprite
	void updatePosition(StaticSprite* platforms);
};

#endif
