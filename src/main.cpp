#include "FrameRate.hpp"
// #include "Hitbox.hpp"
#include "Enemy.hpp"
#include "Player.hpp"
#include "StaticSprite.hpp"

int main()
{
	bool show_hitboxes = false;

	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Game");

	Player player(sf::Vector2f(500.f, 0.f), sf::Vector2f());
	StaticSprite platforms[2] = { StaticSprite("assets/platform.png", sf::Vector2f(10.f, 500.f)),
		StaticSprite("assets/platform.png", sf::Vector2f(1100.f, 720.f)) };
	Enemy enemies[2] = { Enemy(sf::Vector2f(0.f, 210.f), sf::Vector2f()),
		Enemy(sf::Vector2f(1920.f, 420.f), sf::Vector2f()) };
	FrameRateTracker frame_tracker;

	// Main Game Loop
	sf::Event event;
	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
				case sf::Event::Closed:
					window.close();
					break;

				case sf::Event::KeyPressed:
					player.handleKeyPress(event.key.code);
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) && event.key.code == sf::Keyboard::B)
					{
						show_hitboxes = !show_hitboxes;
					}
					//Only jumps is the player is on the ground or when they have a jump available
					else if (event.key.code == sf::Keyboard::Space && (player.notGrounded != true || player.jumpsLeft > 0))
					{
						player.vel.y -= 5.f;
						//Deincrements the jump counter
						player.jumpsLeft -= 1;
					}
					break;

				case sf::Event::KeyReleased:
					player.handleKeyRelease(event.key.code);
					break;

				default:
					break;
			}
		}

		player.updatePosition(platforms);

		window.clear();

		for (int i = 0; i < 2; i++)
		{
			enemies[i].updatePosition(platforms, player.pos);

			window.draw(platforms[i].sprite);
			window.draw(enemies[i].sprite);

			if (show_hitboxes)
			{
				window.draw(platforms[i].get_hitbox_outline());
				window.draw(enemies[i].get_hitbox_outline());
			}
		}

		window.draw(player.sprite);
		if (show_hitboxes)
			window.draw(player.get_hitbox_outline());

		frame_tracker.update(std::to_string(player.vel.y));
		window.draw(frame_tracker.text);

		window.display();
	}

	return 0;
}
