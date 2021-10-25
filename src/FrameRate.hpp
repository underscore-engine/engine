#ifndef FrameRateTracker_H
#define FrameRateTracker_H

/**
 * A class to handle the showing of the framerate debugging tool on the screen
 */
class FrameRateTracker
{
private:
	sf::Clock clock;
	unsigned int elapsed_iterations = 0;
	sf::Font font;
	std::string info;

public:
	sf::Text text;
	FrameRateTracker();
	void update();
	void add_info(std::string name, std::string value);
};

#endif
