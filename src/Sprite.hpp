#ifndef Sprite_H
#define Sprite_H

/**
 * A class for anything that will show to a screen with a predefined
 * texture.
 * Note: It does not save its position and size, as this is kept by the physics and hitbox classes.
 *       This is purely for displaying textures.
 *
 * @param texture_name The path to the image for the sprite texture
 * @param start_pos The initial position for the top left of the sprite
 * @param target_size The size that the texture should be scaled to
 */
class Sprite
{
private:
	sf::Texture texture;

public:
	sf::Sprite sprite;
	Sprite(std::string texture_name, sf::Vector2f start_pos, sf::Vector2f target_size);
	Sprite() {};

	void draw(sf::RenderWindow& window);
	void update_sprite(sf::Vector2f pos, sf::Vector2f target_size);
};

#endif