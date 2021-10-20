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
	sf::Vector2f pos2;
	sf::Vector2f size2;
	// Function that calculates and applies Physics vector
	Physics(sf::Vector2f _pos2, sf::Vector2f _size2);
	void applyGravity();
};

#endif