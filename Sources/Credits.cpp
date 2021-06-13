#include "..\Headers\Credits.h"

Credits::Credits() {};

void Credits::SetTexture(std::shared_ptr<MyTexture> texture)
{
	this->texture = texture;
	sprite.setTexture(*this->texture);
}

void Credits::HiglightHoveredButton(sf::Vector2i vec)
{
	sf::Vector2f vecF = { (float)vec.x, (float)vec.y };

	if (back.GetShape().getGlobalBounds().contains(vecF.x, vecF.y))
	{
		back.SetHighlightColor();
	}
	else
	{
		back.SetDefaultColor();
	}
}

void Credits::Draw(sf::RenderWindow* window)
{
	window->draw(sprite);
	back.Draw(window);
}

bool Credits::IsReturnButtonClicked(sf::Vector2i vec)
{
	sf::Vector2f vecF = { (float)vec.x, (float)vec.y };

	return (back.GetShape().getGlobalBounds().contains(vecF.x, vecF.y));
};

void Credits::SetFont(std::shared_ptr<MyFont> font)
{
	this->fontTitleText = font;
	back = Button("RETURN", 325.0f, 700.0f, font);
}