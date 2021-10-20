#include "Physics.hpp"

//Setting a value for g
sf::Vector2f Physics::g { sf::Vector2f(0, 0.06f) };

//Setting a value for terminal velocity
float Physics::termVel {10.f};

Physics::Physics(sf::Vector2f _pos)
{
	//Vectors for acceleration, velocity, and position
	acc = sf::Vector2f();
	vel = sf::Vector2f();
	pos = _pos;
}

void Physics::update(sf::Vector2f horizontalVel = sf::Vector2f())
{
	acc = sf::Vector2f();
	acc += g;
	//If the value of the next vertical velocity is positive (going down) and is greater than terminal velocity
	//Set it to be the terminal velocity
	if (vel.y+acc.y > 0 && vel.y+acc.y > termVel) {
		vel.y = termVel;
		vel.x = horizontalVel.x;
		pos += vel;
	}
	//Same as above but in case we want a terminal velocity when going up
	//Suspect this will be sorted in the jumping code
	else if (vel.y+acc.y < 0 && vel.y+acc.y < -termVel){
		vel.y = -termVel;
		vel.x = horizontalVel.x;
		pos += vel;
	}
	//If the velocity is in the allowed range functions normally
	else {
		vel += acc;
		vel.x = horizontalVel.x;
		pos += vel;
	}
}
