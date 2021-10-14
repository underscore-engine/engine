class Player
{
private:
	sf::Texture texture;
	sf::Vector2f pos;
	float speed;

	// A map of keys that are 1 if held but 0 if not
	std::map<sf::Keyboard::Key, int> held_keys;

public:
	sf::Sprite sprite;

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
		speed = 3.f;
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

	void updatePosition()
	{
		float dx = held_keys.at(sf::Keyboard::D) - held_keys.at(sf::Keyboard::A);
		float dy = held_keys.at(sf::Keyboard::S) - held_keys.at(sf::Keyboard::W);

		if (dx == 0 && dy == 0)
			return;

		sf::Vector2f vel = sf::Vector2f(dx, dy);

		// Normalise Velocity
		float mag = sqrtf(vel.x * vel.x + vel.y * vel.y);
		vel *= speed / mag;

		pos += vel;
		sprite.setPosition(pos);
	}
};
