#ifndef Player_H
#define Player_H

class Player
{
private:
	sf::Texture texture;
	sf::Vector2f pos;
	float speed;

	// A map of keys that are 1 if held but 0 if not
	std::unordered_map<sf::Keyboard::Key, bool> held_keys;

public:
	sf::Sprite sprite;
	Player();
	void handleKeyPress(sf::Keyboard::Key key);
	void handleKeyRelease(sf::Keyboard::Key key);
	sf::Vector2f calculateVelocity();
	void updatePosition();
};

#endif
