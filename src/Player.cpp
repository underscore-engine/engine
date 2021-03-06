#include "Player.hpp"
#include <string>

unsigned int Player::maxJumps { 1 };

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
	health = 100;
	sprite.setPosition(pos);
}

void Player::handleKeyPress(sf::Keyboard::Key key)
{
	const bool jump_not_held = !held_keys[sf::Keyboard::Space] || isGrounded;
	if (key == sf::Keyboard::Space && jumpsLeft > 0 && jump_not_held)
	{
		vel.y -= 5.f;
		if (!isGrounded)
			jumpsLeft--;
	}

	if (held_keys.find(key) != held_keys.end())
		held_keys[key] = 1;
}

void Player::handleKeyRelease(sf::Keyboard::Key key)
{
	if (held_keys.find(key) != held_keys.end())
		held_keys[key] = 0;
}

float Player::getHorizontalMovement()
{
	return speed * (held_keys.at(sf::Keyboard::D) - held_keys.at(sf::Keyboard::A));
}

void Player::updatePosition(StaticSprite* platforms)
{
	update(getHorizontalMovement());

	isGrounded = false;

	CollisionFix fix;
	for (unsigned int i = 0; i < 3; i++)
	{
		if (overlaps(platforms[i]))
		{
			fix = correctHitboxOverlap(platforms[i]);
			if (fix.h1_direction() == Direction::up)
			{
				jumpsLeft = maxJumps;
				isGrounded = true;
			}
		}
	}

	sprite.setPosition(pos);
}

sf::Vector2f Player::getPosition()
{
	return pos;
}

void Player::handleCollide(Enemy enemy)
{
	float overlap_damage = 0.05;

	if (overlaps(enemy))
	{
		health -= overlap_damage;
	}
}

void Player::updateHealth()
{
	font.loadFromFile("assets/opensans.ttf");
	std::string health_text = std::to_string(static_cast<int>(health));
	health_display = sf::Text(health_text, font);

	health_display.setCharacterSize(30);
	health_display.setFillColor(sf::Color::White);
	health_display.setPosition(sf::Vector2f(pos.x, pos.y - size.y / 2));
}

float Player::getHealth()
{
	return health;
}