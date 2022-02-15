#ifndef Game_H
#define Game_H

#include "Enemy.hpp"
#include "FrameRate.hpp"
#include "Player.hpp"
#include "WindowStates/State.hpp"

/**
 * The main game object to control all game functionality.
 * Keeps references to player, platforms, and enemies, while also running collision logic.
 *
 * @param window A reference to the main window object
 */
class Game
{
private:
	sf::RenderWindow& window;

	FrameRateTracker frame_tracker;

	Player player;
	std::vector<StaticSprite*> platforms;
	std::vector<Enemy*> enemies;

public:
	sf::View player_view;
	bool show_hitboxes = false;

	Game(sf::RenderWindow& window);

	void reset_positions(bool hard_reset);

	void handleKeyPress(sf::Keyboard::Key key_code);
	void handleKeyRelease(sf::Keyboard::Key key_code);

	void moveViewToPlayer();
	void draw();

	void update(WindowStates& next_state);
};

#endif
