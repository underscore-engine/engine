#include "Physics.hpp"

sf::Vector2f Physics::g { sf::Vector2f(0, 0.01f) };

Physics::Physics(sf::Vector2f _pos)
{
	//Vectors for acceleration, velocity, and position
	acc = sf::Vector2f();
	vel = sf::Vector2f();
	pos = _pos;
}

void Physics::update()
{
	acc = sf::Vector2f();
	acc += g;
	vel += acc;
	pos += vel;
}
