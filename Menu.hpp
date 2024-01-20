#include <SFML/Graphics.hpp>
#include <array>
#include <memory>
#include "Button.hpp"
#include <iostream>

class Menu
{
private:
	static constexpr size_t NUMBER_OF_BUTTONS = 3;
	std::vector<std::unique_ptr<Button>> buttons;

	int is_active;
public:
	Menu();
	void handleMenu(sf::RenderWindow& window);
	void handleMenuEvent(sf::RenderWindow& window, sf::Event event);

	void pushBack(std::unique_ptr<Button> button);
};