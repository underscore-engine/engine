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
	speed = 3.f;
	sprite.setPosition(pos);
}

sf::Vector2f Enemy::calculateVelocity()
{
	/**
	const float dx = 0;
	// const float dy = held_keys.at(sf::Keyboard::S) - held_keys.at(sf::Keyboard::W);
	const float dy = 0;

	if (dx == 0 && dy == 0)
		return sf::Vector2f();

	sf::Vector2f vel = sf::Vector2f(dx, dy);

	// Normalise Velocity
	const float mag = sqrtf(vel.x * vel.x + vel.y * vel.y);
	vel *= speed / mag;
	return vel; */
	sf::Vector2f vel(2.f, 0.f);

	if (pos.x > 1500.f)
	{
		vel.x += -4.f;
	}
	if (pos.x < 500.f)
	{
		vel.x += 4.f;
	}

	return vel;
}

void Enemy::updatePosition(StaticSprite* platforms)
{
	sf::Vector2f vel = calculateVelocity();

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