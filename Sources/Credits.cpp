#include "..\Headers\Credits.h"

Credits::Credits() {};

void Credits::SetTexture(std::shared_ptr<MyTexture> texture)
{
	this->texture = texture;
	sprite.setTexture(*this->texture);
}

void Credits::Draw(sf::RenderWindow* window)
{
	window->draw(sprite);
	back.Draw(window);
}

bool Credits::CheckIfButtonWasClicked(sf::Vector2i vec)
{
	sf::Vector2f vecF = { (float)vec.x, (float)vec.y };

	return (back.rectangle.getGlobalBounds().contains(vecF.x, vecF.y));
};

void Credits::SetFont(std::shared_ptr<MyFont> font)
{
	this->fontTitleText = font;
	back = Button("RETURN", 325.0f, 700.0f, font);
}