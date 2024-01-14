#include <SFML/Graphics.hpp>
#include <iostream>
#include "Menu.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "Button Class");
    Menu menu;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            menu.handleMenuEvent(window, event);
        }

        window.clear();

        menu.handleMenu(window);

        window.display();
    }

    return 0;
}