// basic enemy class template

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

	// Finds closest path to player
	// Assuming no obstacles
	sf::Vector2f vel;
	vel.x = player_pos.x - pos.x;
	vel.y = 0;

	// Normalises path to a unit vector
	const float mag = sqrtf(vel.x * vel.x + vel.y * vel.y);
	vel *= speed / mag;

	// Moves enemy towards player
	pos += vel;

	sf::Vector2f new_vels[2];
	for (unsigned int i = 0; i < 1; i++)
	{
		if (overlaps(platforms[i]))
		{
			correctHitboxOverlap(new_vels, platforms[i], vel, sf::Vector2f());
			pos += new_vels[0];
			/* (Would update velocity of second object, but its static, and so vel always = 0) */
		}
	}

	sprite.setPosition(pos);
}