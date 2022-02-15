#include "Player.hpp"
#include <string>

unsigned int Player::maxJumps { 1 };

Player::Player(sf::Vector2f _pos, sf::Vector2f target_size) :
	Hitbox { _pos, target_size },
	Sprite { "assets/main_character.png", _pos, target_size }
{
	// Initialise Held Keys Map
	held_keys[sf::Keyboard::W] = 0;
	held_keys[sf::Keyboard::A] = 0;
	held_keys[sf::Keyboard::S] = 0;
	held_keys[sf::Keyboard::D] = 0;
	held_keys[sf::Keyboard::Space] = 0;

	speed = 3.f;
	health = 100;
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

void Player::updatePosition(std::vector<StaticSprite*>& platforms)
{
	update(getHorizontalMovement());

	isGrounded = false;

	CollisionFix fix;
	for (StaticSprite* platform : platforms)
	{
		if (overlaps(*platform))
		{
			fix = correctHitboxOverlap(*platform);
			if (fix.h1_direction() == Direction::up)
			{
				jumpsLeft = maxJumps;
				isGrounded = true;
			}
		}
	}

	sprite.setPosition(pos);
}

void Player::setDetails(sf::Vector2f _pos, sf::Vector2f _size)
{
	pos = _pos;
	update_sprite(pos, _size);
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
