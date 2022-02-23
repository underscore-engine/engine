#include "StaticSprite.hpp"

StaticSprite::StaticSprite(std::string texture_name, sf::Vector2f _pos, sf::Vector2f target_size) :
	Hitbox { _pos, target_size },
	Sprite { texture_name, _pos, target_size }
{}
