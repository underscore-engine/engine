#include "Physics.hpp"

Physics::Physics(sf::Vector2f __pos, sf::Vector2f __size)
{
	pos2 = __pos;
	size2 = __size;
}

void Physics::applyGravity()
{
	sf::Vector2f gravity(0.f, 5.f);
}
