#include "MenuState.hpp"

MenuState::MenuState(sf::RenderWindow& window) :
	BaseState { window }
{
	Menu menu(window.getSize().x, window.getSize().y);
}

void MenuState::handle_event(sf::Event& event)
{
	switch (event.type)
	{
		case sf::Event::Closed:
			window.close();
			break;
		case sf::Event::MouseButtonPressed:
			menu.handleButtonPress(sf::Mouse::getPosition());
			break;
		default:
			break;
	}
}

void MenuState::update()
{
	if (menu.getSelection(0))
	{
		std::cout << "Leave menu" << std::endl;
	}
	else if (menu.getSelection(2))
	{
		window.close();
	}
}

void MenuState::show()
{
	window.clear();

	menu.draw(window);
	window.display();
}