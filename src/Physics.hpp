#ifndef Physics_H
#define Physics_H

/**
 * Physics class that handles physics such as gravity for any object that needs it
 *
 * @param _pos2 The initial position of the top left of the player
 * @param _size2 The width and height of the player's hitbox
 *
 */
class Physics
{
public:
	// Gravitational constant
	static sf::Vector2f g;
	// The maximum velocity magnitude that the player can be moving
	static float termVel;

	// The maximum number of jumps
	static int maxJumps;
	// The number of jumps available - resets upon touching ground
	int jumpsLeft;

	sf::Vector2f pos;
	sf::Vector2f vel;
	sf::Vector2f acc;

	// Function that calculates and applies Physics vector
	Physics(sf::Vector2f pos);
	void update(float horizontalVel);
};

#endif