#ifndef Player_H
#define Player_H

#include "Enemy.hpp"
#include "Hitbox.hpp"
#include "Sprite.hpp"
#include "StaticSprite.hpp"

#include <unordered_map>

/**
 * The main player class that the user controls
 *
 * @param pos The initial position of the top left of the player
 * @param size The width and height of the player's hitbox
 */
class Player : public Hitbox, public Sprite
{
private:
	float speed;
	// A map of keys that are 1 if held but 0 if not
	std::unordered_map<sf::Keyboard::Key, bool> held_keys;

	// The maximum number of jumps between ground touches
	// (Does not include initial jump)
	static unsigned int maxJumps;
	// The number of jumps available - resets upon touching ground
	unsigned int jumpsLeft;

	// Whether the object was pushed up on the previous frame
	bool isGrounded;

	sf::Font font;
	int elapsed_iterations;

public:
	float health;

	Player(sf::Vector2f pos, sf::Vector2f size);
	Player();
	// Handles a key press event from the keyboard
	void handleKeyPress(sf::Keyboard::Key key);
	// Handles a key release event from the keyboard
	void handleKeyRelease(sf::Keyboard::Key key);
	// Calculates the velocity based on what keys are pressed down
	float getHorizontalMovement();
	// Updates the position of the sprite
	void updatePosition(std::vector<StaticSprite*>& platforms);
	// Handled when space is pressed
	void handleJump();

	void setDetails(sf::Vector2f pos, sf::Vector2f _size);
	void handleCollide(Enemy enemy);
	sf::Text health_display;
	void updateHealth();
};

#endif
