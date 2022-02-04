#include "Enemy.hpp"
#include "Sprite.hpp"

Enemy::Enemy(sf::Vector2f _pos, sf::Vector2f target_size) :
	Hitbox { _pos, target_size },
	Sprite { "assets/enemy.png", _pos, target_size }
{}

Enemy::Enemy() :
	Hitbox { sf::Vector2f(), sf::Vector2f() },
	Sprite { "assets/enemy.png", sf::Vector2f(), sf::Vector2f() }
{}

void Enemy::updatePosition(StaticSprite* platforms, sf::Vector2f player_pos)
{
	float speed = 0.4f;
	const float horiz_vel = player_pos.x > pos.x ? speed : -speed;
	update(horiz_vel);

	for (unsigned int i = 0; i < 3; i++)
	{
		if (overlaps(platforms[i]))
		{
			correctHitboxOverlap(platforms[i]);
		}
	}

	sprite.setPosition(pos);
}

void Enemy::setPosition(sf::Vector2f _pos)
{
	pos = _pos;
	update_sprite(pos, size);
}
