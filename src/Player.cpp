class Player
{
public:
	sf::Texture texture;
	sf::Sprite sprite;

	Player()
	{
		if (!texture.loadFromFile("main_character.png"))
		{}

		sprite.setTexture(texture);
		sprite.setPosition(sf::Vector2f(20.f, 50.f));
	}

	void move_right()
	{
		sprite.move(sf::Vector2f(20.f, 0.f));
	}

	void move_left()
	{
		sprite.move(sf::Vector2f(-20.f, 0.f));
	}

	void move_down()
	{
		sprite.move(sf::Vector2f(0.f, 20.f));
	}

	void move_up()
	{
		sprite.move(sf::Vector2f(0.f, -20.f));
	}
};
