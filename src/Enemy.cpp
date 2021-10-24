#include "Enemy.hpp"

Enemy::Enemy(sf::Vector2f _pos, sf::Vector2f _size) :
	Hitbox { _pos, _size }
{
	// Load Texture
	texture.loadFromFile("assets/enemy.png");
	sprite.setTexture(texture);
	size = sf::Vector2f(texture.getSize());

	// Initialise Position
	pos = _pos;

	sprite.setPosition(pos);
}

void Enemy::updatePosition(StaticSprite* platforms, sf::Vector2f player_pos)
{
	float speed = 0.1f;

	// Gets direction to player
	const float horiz_vel = player_pos.x > pos.x ? speed : -speed;
	update(horiz_vel);

	for (unsigned int i = 0; i < 2; i++)
	{
		if (overlaps(platforms[i]))
		{
			correctHitboxOverlap(platforms[i]);
		}
	}

	sprite.setPosition(pos);
}
