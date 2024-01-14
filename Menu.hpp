#include <SFML/Graphics.hpp>
#include <array>
#include <memory>
#include "Button.hpp"
#include <iostream>

class Menu
{
private:
	std::array<std::unique_ptr<Button>, 3> buttons;
public:
	Menu();
	void handleMenu(sf::RenderWindow& window);
	void handleMenuEvent(sf::RenderWindow& window, sf::Event event, std::function<void()> foo);
};