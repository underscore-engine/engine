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
		case sf::Event::MouseButtonPressed:
			menu.handleButtonPress(sf::Mouse::getPosition(window));
			break;
		default:
			break;
	}
}

void MenuState::update(WindowStates& next_state)
{
	switch (menu.hasButtonBeenPressed())
	{
		case 0:
			next_state = WindowStates::GAME;
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
	menu.draw(window);
}