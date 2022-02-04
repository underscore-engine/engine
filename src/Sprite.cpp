#include "Sprite.hpp"

Sprite::Sprite(std::string texture_name, sf::Vector2f start_pos, sf::Vector2f target_size)
{
	// Load Texture
	texture.loadFromFile(texture_name);
	sprite.setTexture(texture);

	const sf::FloatRect bounds = sprite.getLocalBounds();
	sprite.setScale(target_size.x / bounds.width, target_size.y / bounds.height);

	// Initialise Position
	sprite.setPosition(start_pos);
}

void Sprite::draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}

void Sprite::update_sprite(sf::Vector2f pos, sf::Vector2f target_size)
{
	const sf::FloatRect bounds = sprite.getLocalBounds();
	sprite.setScale(target_size.x / bounds.width, target_size.y / bounds.height);
	sprite.setPosition(pos);
}
