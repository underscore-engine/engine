#ifndef Hitbox_H
#define Hitbox_H

#include "Physics.hpp"

enum Direction
{
	none,
	up,
	down,
	right,
	left,
	diagonal
};

/**
 * The object to be returned from the Hitbox::correctHitboxOverlap function.
 * It contains the displacement vectors for each object as well as a method to
 * get what direction each will move.
 */
struct CollisionFix
{
private:
	static Direction getDirectionFromVector(sf::Vector2f v);

public:
	sf::Vector2f h1_displacement {};
	sf::Vector2f h2_displacement {};
	Direction h1_direction();
	Direction h2_direction();
};

/**
 * An inherited base class to handle collision detection between sprites
 * @param pos A vector for the top left point of the rect
 * @param size A vector giving the width and height of the rect
 */
class Hitbox : public Physics
{
private:
	// Finds the horizontal displacement to correct an overlap
	float* calculateHitboxOverlapX(Hitbox other);
	// Finds the vertical displacement to correct an overlap
	float* calculateHitboxOverlapY(Hitbox other);
	/**
	 * Handles two hitboxes overlapping by calculating the offset necessary
	 * to move them back to where they are no longer overlapping.
	 *
	 * @param other The Hitbox that this has collided with
	 * @return Two corrected displacement vectors to move the objects in order
	 *         to undo the collision.
	 */
	CollisionFix calculateHitboxOverlap(Hitbox other);

	void resetVelOnCollision(Direction dir);

public:
	sf::Vector2f size;
	Hitbox(sf::Vector2f pos, sf::Vector2f size);
	// Finds whether two Hitboxes truly overlap
	bool overlaps(Hitbox h);
	// Handles a collision by running the calculation and updating the velocities
	// and positions of both objects.
	CollisionFix correctHitboxOverlap(Hitbox other);
	// Returns a red outline shape to show the user the hitbox (For testing purposes)
	sf::RectangleShape get_hitbox_outline();
};

#endif
