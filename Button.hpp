#include <SFML/Graphics.hpp>
#include <functional>

class Button : public sf::RectangleShape
{
private:
	sf::Text text;
	sf::Font font;
	int hover_color_change;
	float hover_parameter;
public:
	Button(
		sf::Vector2f _button_size = sf::Vector2f(150, 50),
		sf::Color _button_color = sf::Color::Blue,
		sf::Vector2f _button_position = sf::Vector2f(0, 0),
		std::string _font_name = std::string("font.ttf"),
		std::string _button_text = std::string("Button"),
		int _font_size = 20,
		sf::Color _font_color = sf::Color::White,
		sf::Vector2f _text_position = sf::Vector2f(0, 0)
	);
	sf::Text getText();
	sf::Font getFont();
	void setText(std::string _text);
	void setTextPosition(sf::Vector2f _text_position);
	int isCursorOverButton(sf::RenderWindow& window);
	void hoverButton(sf::RenderWindow& window);
	void unhoverButton(sf::RenderWindow& window);
	void onClick(std::function<void()> foo);

	void handleButton(sf::RenderWindow& window);
	void handleButtonEvent(sf::RenderWindow& window, sf::Event event, std::function<void()> foo);
};