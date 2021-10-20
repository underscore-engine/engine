#ifndef Player_H
#define Player_H

#include "Hitbox.hpp"
// #include "Physics.hpp"
#include "StaticSprite.hpp"

/**
 * The main player class that the user controls
 *
 * @param _pos The initial position of the top left of the player
 * @param _size The width and height of the player's hitbox
 */
class Player : public Hitbox
{
private:
	sf::Texture texture;
	float speed;

	// A map of keys that are 1 if held but 0 if not
	std::unordered_map<sf::Keyboard::Key, bool> held_keys;

public:
	sf::Sprite sprite;
	Player(sf::Vector2f _pos, sf::Vector2f _size);
	// Handles a key press event from the keyboard
	void handleKeyPress(sf::Keyboard::Key key);
	// Handles a key release event from the keyboard
	void handleKeyRelease(sf::Keyboard::Key key);
	// Calculates the velocity based on what keys are pressed down
	sf::Vector2f calculateVelocity();
	// Updates the position of the sprite
	void updatePosition(StaticSprite* platforms);
};

#endif
