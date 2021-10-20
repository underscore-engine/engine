#include "FrameRate.hpp"

FrameRateTracker::FrameRateTracker()
{
	font.loadFromFile("assets/opensans.ttf");
	text = sf::Text("0 fps", font);

	text.setCharacterSize(30);
	text.setFillColor(sf::Color::White);
	text.setPosition(sf::Vector2f(10.f, 10.f));
}

void FrameRateTracker::update()
{
	elapsed_iterations++;
	if (elapsed_iterations >= 80)
	{
		float fps = (float)elapsed_iterations / clock.getElapsedTime().asSeconds();
		text.setString(std::to_string(fps) + " fps");

		clock.restart();
		elapsed_iterations = 0;
	}
}
