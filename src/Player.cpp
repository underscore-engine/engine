#include "Player.hpp"

Player::Player(sf::Vector2f _pos, sf::Vector2f _size) :
	Hitbox { _pos, _size }
{
	// Load Texture
	texture.loadFromFile("assets/main_character.png");
	sprite.setTexture(texture);
	size = sf::Vector2f(texture.getSize());

	// Initialise Held Keys Map
	held_keys[sf::Keyboard::W] = 0;
	held_keys[sf::Keyboard::A] = 0;
	held_keys[sf::Keyboard::S] = 0;
	held_keys[sf::Keyboard::D] = 0;
	held_keys[sf::Keyboard::Space] = 0;

	// Initialise Position
	pos = _pos;
	speed = 3.f;
	sprite.setPosition(pos);
}

void Player::handleKeyPress(sf::Keyboard::Key key)
{
	if (held_keys.find(key) != held_keys.end())
	{
		held_keys[key] = 1;
	}
}

void Player::handleKeyRelease(sf::Keyboard::Key key)
{
	if (held_keys.find(key) != held_keys.end())
	{
		held_keys[key] = 0;
	}
}

sf::Vector2f Player::calculateVelocity()
{
	const float dx = held_keys.at(sf::Keyboard::D) - held_keys.at(sf::Keyboard::A);
	// const float dy = held_keys.at(sf::Keyboard::S) - held_keys.at(sf::Keyboard::W);
	const float dy = held_keys.at(sf::Keyboard::Space);

	if (dx == 0 && dy == 0)
		return sf::Vector2f();

	sf::Vector2f vel = sf::Vector2f(dx, dy);

	// Normalise Velocity
	const float mag = sqrtf(vel.x * vel.x + vel.y * vel.y);
	vel *= speed / mag;
	return vel;
}

void Player::updatePosition(StaticSprite* platforms)
{
	sf::Vector2f vel = calculateVelocity();

	if (vel.x == 0 && vel.y == 0)
		return;

	pos += vel;

	sf::Vector2f new_vels[2];
	for (unsigned int i = 0; i < 2; i++)
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
