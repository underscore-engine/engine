#ifndef Hitbox_H
#define Hitbox_H

/**
 * An inherited base class to handle collision detection between sprites
 * @param _pos A vector for the top left point of the rect
 * @param _size A vector giving the width and height of the rect
 */
class Hitbox
{
private:
	// Finds the horizontal displacement to correct an overlap
	float* correctHitboxOverlapX(Hitbox other, float dx, float other_dx);
	// Finds the vertical displacement to correct an overlap
	float* correctHitboxOverlapY(Hitbox other, float dy, float other_dy);

public:
	sf::Vector2f pos;
	sf::Vector2f size;
	Hitbox(sf::Vector2f _pos, sf::Vector2f _size);
	// Finds whether two Hitboxes truly overlap
	bool overlaps(Hitbox h);
	/**
	 * Handles two hitboxes overlapping by calculating the offset necessary
	 * to move them back to where they are no longer overlapping.
	 *
	 * @param new_vels The array pointer to fill with the new x and y displacement vectors
	 * @param other The Hitbox that this has collided with
	 * @param vel The change in position of this Hitbox that caused the collision
	 * @param other_vel The change in position of the other Hitbox that caused the collision
	 * @return Two corrected displacement vectors with the first being for
	 *         the Hitbox that ran the function. These should replace the passed
	 *         velocity paramters.
	 */
	sf::Vector2f* correctHitboxOverlap(sf::Vector2f* new_vels, Hitbox other, sf::Vector2f vel, sf::Vector2f other_vel);
	// Returns a red outline shape to show the user the hitbox (For testing purposes)
	sf::RectangleShape get_hitbox_outline();
};

#endif
