#include "Menu.hpp"

Menu::Menu()
{
	auto start_button = std::make_unique<Button>();
	auto credits_button = std::make_unique<Button>();
	auto quit_button = std::make_unique<Button>();

	buttons.at(0) = std::move(start_button);
	buttons.at(1) = std::move(credits_button);
	buttons.at(2) = std::move(quit_button);

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
	buttons.at(0)->handleButton(window);
	buttons.at(1)->handleButton(window);
	buttons.at(2)->handleButton(window);
}

void Menu::handleMenuEvent(sf::RenderWindow & window, sf::Event event, std::function<void()> foo)
{
	buttons.at(0)->handleButtonEvent(window, event, foo);
	buttons.at(1)->handleButtonEvent(window, event, foo);
	buttons.at(2)->handleButtonEvent(window, event, foo);
}