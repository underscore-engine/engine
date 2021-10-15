#include "Player.hpp"

Player::Player()
{
	// Load Texture
	texture.loadFromFile("assets/main_character.png");
	sprite.setTexture(texture);

	// Initialise Held Keys Map
	held_keys[sf::Keyboard::W] = 0;
	held_keys[sf::Keyboard::A] = 0;
	held_keys[sf::Keyboard::S] = 0;
	held_keys[sf::Keyboard::D] = 0;

	// Initialise Position
	pos = sf::Vector2f(20.f, 50.f);
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
	const float dy = held_keys.at(sf::Keyboard::S) - held_keys.at(sf::Keyboard::W);

	if (dx == 0 && dy == 0)
		return sf::Vector2f();

	sf::Vector2f vel = sf::Vector2f(dx, dy);

	// Normalise Velocity
	const float mag = sqrtf(vel.x * vel.x + vel.y * vel.y);
	vel *= speed / mag;
	return vel;
}

void Player::updatePosition()
{
	const sf::Vector2f vel = calculateVelocity();
	pos += vel;
	sprite.setPosition(pos);
}
