#include "Menu.hpp"

Menu::Menu()
{
	is_active = 0;

	auto start_button = std::make_unique<Button>();
	auto credits_button = std::make_unique<Button>();
	auto quit_button = std::make_unique<Button>();

	buttons.push_back(std::move(start_button));
	buttons.push_back(std::move(credits_button));
	buttons.push_back(std::move(quit_button));

	buttons.at(0)->setPosition(sf::Vector2f(0, 0));
	buttons.at(0)->setTextPosition(sf::Vector2f(0, 0));
	buttons.at(0)->setText("0");

	buttons.at(1)->setPosition(sf::Vector2f(0, 75));
	buttons.at(1)->setTextPosition(sf::Vector2f(0, 75));
	buttons.at(1)->setText("1");

	buttons.at(2)->setPosition(sf::Vector2f(0, 150));
	buttons.at(2)->setTextPosition(sf::Vector2f(0, 150));
	buttons.at(2)->setText("2");
}

void Menu::handleMenu(sf::RenderWindow& window)
{
	for (auto& it : buttons)
	{
		it->handleButton(window);
	}
}

void Menu::handleMenuEvent(sf::RenderWindow& window, sf::Event event)
{
	for (auto& it : buttons)
	{
		it->handleButtonEvent(window, event);
	}
}

void Menu::pushBack(std::unique_ptr<Button> button)
{
	buttons.push_back(std::move(button));
}