#ifndef Game_H
#define Game_H

#include "Enemy.hpp"
#include "FrameRate.hpp"
#include "Player.hpp"
#include "WindowStates/State.hpp"

class Game
{
private:
	sf::RenderWindow& window;

	FrameRateTracker frame_tracker;

	Player player;
	StaticSprite platforms[3];
	Enemy enemies[2];

public:
	sf::View player_view;
	bool show_hitboxes;

	Game(sf::RenderWindow& window);

	void reset_positions(bool hard_reset);

	void handleKeyPress(sf::Keyboard::Key key_code);
	void handleKeyRelease(sf::Keyboard::Key key_code);

	void moveViewToPlayer();
	void draw();

	void update(WindowStates& next_state);
};

#endif
