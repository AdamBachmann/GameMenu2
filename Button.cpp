#include "Button.hpp"
#include <iostream>

Button::Button(
	sf::Vector2f _button_size, 
	sf::Color _button_color, 
	sf::Vector2f _button_position, 
	std::string _font_name, 
	std::string _button_text, 
	int _font_size, 
	sf::Color _font_color, 
	sf::Vector2f _text_position)
{
	sf::RectangleShape::setSize(_button_size);
	sf::RectangleShape::setFillColor(_button_color);
	sf::RectangleShape::setPosition(_button_position);

	font.loadFromFile(_font_name);

	text.setFont(font);
	text.setString(_button_text);
	text.setCharacterSize(_font_size);
	text.setFillColor(_font_color);
	text.setPosition(_text_position);

	hover_color_change = 0;
	hover_parameter = 0.7;
}

sf::Text Button::getText()
{
	return text;
}

sf::Font Button::getFont()
{
	return font;
}

void Button::setText(std::string _text)
{
	text.setString(_text);
}

void Button::setTextPosition(sf::Vector2f _text_position)
{
	text.setPosition(_text_position);
}

int Button::isCursorOverButton(sf::RenderWindow& window)
{
	if (sf::Mouse::getPosition(window).x >= this->getPosition().x &&
		sf::Mouse::getPosition(window).x <= this->getPosition().x + this->getGlobalBounds().width &&
		sf::Mouse::getPosition(window).y >= this->getPosition().y &&
		sf::Mouse::getPosition(window).y <= this->getPosition().y + this->getGlobalBounds().height)
	{
		return 1;
	}

	return 0;
}

void Button::hoverButton(sf::RenderWindow& window)
{
	if (hover_color_change == 0)
	{
		sf::Color darkerColor = sf::Color(
			this->getFillColor().r * hover_parameter,
			this->getFillColor().g * hover_parameter,
			this->getFillColor().b * hover_parameter
		);

		this->setFillColor(darkerColor);

		hover_color_change = 1;
	}
}

void Button::unhoverButton(sf::RenderWindow& window)
{
	if (hover_color_change == 1)
	{
		sf::Color darkerColor = sf::Color(
			this->getFillColor().r * (1 / hover_parameter),
			this->getFillColor().g * (1 / hover_parameter),
			this->getFillColor().b * (1 / hover_parameter)
		);

		this->setFillColor(darkerColor);

		hover_color_change = 0;
	}
}

void Button::onClick(std::function<void()> foo)
{
	return foo();
}

void Button::handleButton(sf::RenderWindow& window)
{
	if (isCursorOverButton(window))
	{
		hoverButton(window);
	}
	else
	{
		unhoverButton(window);
	}

	window.draw(*this);
	window.draw(this->text);
}

void Button::handleButtonEvent(sf::RenderWindow& window, sf::Event event, std::function<void()> foo)
{
	if (event.type == sf::Event::MouseButtonReleased && isCursorOverButton(window))
	{
		onClick(foo);
	}
}