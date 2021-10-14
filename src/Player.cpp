#include <map>

class Player
{
private:
	// A map of keys that are 1 if held but 0 if not
	std::map<sf::Keyboard::Key, int> held_keys;

public:
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Vector2f pos;
	float speed;

	Player()
	{
		// Load Texture
		texture.loadFromFile("assets/main_character.png");
		sprite.setTexture(texture);

		// Initialise Held Keys Map
		held_keys[sf::Keyboard::W] = 0;
		held_keys[sf::Keyboard::A] = 0;
		held_keys[sf::Keyboard::S] = 0;
		held_keys[sf::Keyboard::D] = 0;

		// Initialise Position
		pos = sf::Vector2f(20.f, 50.f);
		speed = 5.f;
		sprite.setPosition(pos);
	}

	void handleKeyPress(sf::Keyboard::Key key)
	{
		if (held_keys.find(key) != held_keys.end())
		{
			held_keys[key] = 1;
		}
	}

	void handleKeyRelease(sf::Keyboard::Key key)
	{
		if (held_keys.find(key) != held_keys.end())
		{
			held_keys[key] = 0;
		}
	}

	void update()
	{
		float dx = (held_keys.at(sf::Keyboard::D) - held_keys.at(sf::Keyboard::A)) * speed;
		float dy = (held_keys.at(sf::Keyboard::S) - held_keys.at(sf::Keyboard::W)) * speed;
		pos += sf::Vector2f(dx, dy);
		sprite.setPosition(pos);
	}
};
