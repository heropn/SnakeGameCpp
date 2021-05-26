#include "../Headers/Button.h"

Button::Button() {}

Button::Button(std::string content, float position_x, float position_y, std::shared_ptr<MyFont> fontPtr) : fontPtr(fontPtr)
{
	rectangle.setFillColor(sf::Color::Green);
	rectangle.setSize(sf::Vector2f(350, 65));
	rectangle.setPosition(position_x, position_y);

	text.setString(content);
	text.setFont(*fontPtr);
	text.setCharacterSize(50);

	float xPos = (position_x + 350.0f / 2.0f) - (text.getLocalBounds().width / 2.0f); // wspó³rzêdne tekstu, ustawione ¿eby wyœrodkowaæ napis wzglêdem przycisku
	float yPos = (position_y + 65.0f / 2.0f) - (text.getLocalBounds().height / 2.0f) - 7.0f; // -7.0 = 1/4 rozmiaru czcionki 
	text.setPosition(xPos, yPos);
}

void Button::Draw(sf::RenderWindow* window) 
{
	window->draw(rectangle);
	window->draw(text);
}