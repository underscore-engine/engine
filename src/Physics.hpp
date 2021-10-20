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
	sf::Vector2f pos;
	sf::Vector2f vel;
	sf::Vector2f acc;
	static sf::Vector2f g;
	static float termVel;
	// Function that calculates and applies Physics vector
	Physics(sf::Vector2f pos);
	void update(sf::Vector2f horizontalVel);
};

#endif