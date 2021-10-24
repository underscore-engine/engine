#ifndef Physics_H
#define Physics_H

/**
 * Physics class that handles physics such as gravity for any object that needs it.
 * @param pos The initial position of the top left of the phyiscal object
 */
class Physics
{
public:
	// Gravitational constant
	static sf::Vector2f g;
	// The maximum velocity magnitude that the player can be moving
	static float termVel;

	sf::Vector2f pos;
	sf::Vector2f vel;
	sf::Vector2f acc;

	// Function that calculates and applies Physics vector
	Physics(sf::Vector2f pos);
	void update(float horizontalVel);
};

#endif