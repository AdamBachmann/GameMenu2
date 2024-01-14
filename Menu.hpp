#include <SFML/Graphics.hpp>
#include <array>
#include <memory>
#include "Button.hpp"
#include <iostream>

class Menu
{
private:
	static constexpr size_t NUMBER_OF_BUTTONS = 3;
	std::array<std::unique_ptr<Button>, NUMBER_OF_BUTTONS> buttons;
public:
	Menu();
	void handleMenu(sf::RenderWindow& window);
	void handleMenuEvent(sf::RenderWindow& window, sf::Event event);
};