#include "StaticSprite.hpp"

StaticSprite::StaticSprite(std::string texture_name, sf::Vector2f _pos) :
	Hitbox { _pos, sf::Vector2f() }
{
	// Load Texture
	texture.loadFromFile(texture_name);
	sprite.setTexture(texture);
	size = sf::Vector2f(texture.getSize());

	// Initialise Position
	sprite.setPosition(pos);
}
