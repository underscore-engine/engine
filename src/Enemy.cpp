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
	sf::Vector2f vel(2.f, 0.f);

	sprite.setPosition(pos);
}

void Enemy::calculateVelocity()
{
	return;

	float speed;

	bool moving_right;
	bool moving_left;

	if (pos.x > 1500.f)
	{
		moving_left = true;
		moving_right = false;
	}
	//if (pos.x < 50.f)
	//{
	//	moving_left = false;
	//	moving_right = true;
	//}

	if (moving_left)
	{
		speed = 2.f;
		vel.x = speed;
	}
	else if (moving_right)
	{
		speed = -2.f;
		vel.x = speed;
	}
}

void Enemy::updatePosition(StaticSprite* platforms)
{

	//calculateVelocity();

	//sf::Vector2f vel(1.f,0.f);

	//pos += vel;

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