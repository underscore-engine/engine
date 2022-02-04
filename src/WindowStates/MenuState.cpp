#include "MenuState.hpp"

MenuState::MenuState(sf::RenderWindow& window) :
	BaseState { window },
	menu(sf::Vector2u(window.getSize().x, window.getSize().y))
{
}

void MenuState::handle_event(sf::Event& event)
{
	switch (event.type)
	{
		case sf::Event::Closed:
			window.close();
			break;
		case sf::Event::MouseButtonPressed:
			menu.handleButtonPress(sf::Mouse::getPosition(window));
			break;
		default:
			break;
	}
}

void MenuState::update()
{
	switch (menu.hasButtonBeenPressed())
	{
		case 0:
			std::cout << "Play the game" << std::endl;
			break;
		case 1:
			std::cout << "Go to options page" << std::endl;
			break;
		case 2:
			window.close();
			break;
		default:
			break;
	}
}

void MenuState::show()
{
	window.clear();
	menu.draw(window);
	window.display();
}