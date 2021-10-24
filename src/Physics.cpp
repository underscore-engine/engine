#include "Physics.hpp"

sf::Vector2f Physics::g { sf::Vector2f(0, 0.04f) };
float Physics::termVel { 10.f };

Physics::Physics(sf::Vector2f _pos)
{
	//Vectors for acceleration, velocity, and position
	acc = sf::Vector2f();
	vel = sf::Vector2f();
	pos = _pos;
}

void Physics::update(float horizontalVel = 0.f)
{
	acc = sf::Vector2f();
	acc += g;

	vel += acc;
	vel = sf::Vector2f(std::min(horizontalVel, termVel), std::min(vel.y, termVel));

	pos += vel;
}
