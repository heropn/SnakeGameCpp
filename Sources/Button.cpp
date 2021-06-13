#include "../Headers/Button.h"

Button::Button() {}

Button::Button(std::string content, float position_x, float position_y, std::shared_ptr<MyFont> fontPtr) : fontPtr(fontPtr)
{
	SetDefaultColor();
	rectangle.setSize(sf::Vector2f(350, 65));
	rectangle.setPosition(position_x, position_y);

	text.setString(content);
	text.setFont(*fontPtr);
	text.setCharacterSize(50);

	auto rect = text.getLocalBounds();
	text.setOrigin(rect.width / 2, rect.height / 2);

	text.setPosition(position_x + rectangle.getSize().x / 2.0f, position_y + rectangle.getSize().y / 2.0f - 5.0f);
}

void Button::Draw(sf::RenderWindow* window) 
{
	window->draw(rectangle);
	window->draw(text);
}

void Button::SetTextString(const sf::String& str)
{
	text.setString(str);

	auto rect = text.getLocalBounds();
	text.setOrigin(rect.width / 2, rect.height / 2);

	float posX = rectangle.getPosition().x + rectangle.getSize().x / 2.0f;
	float posY = rectangle.getPosition().y + rectangle.getSize().y / 2.0f - 5.0f;

	text.setPosition(posX, posY);
}

void Button::SetHighlightColor()
{
	rectangle.setFillColor(sf::Color(0, 255, 0, 200));
}

void Button::SetDefaultColor()
{
	rectangle.setFillColor(sf::Color(0, 255, 0, 255));
}