#include "..\Headers\Help.h"

Help::Help() {}

void Help::SetTexture(std::shared_ptr<MyTexture> texture)
{
	helpTexture = texture;
	help.setTexture(*helpTexture);
	help.setScale({ 0.9f, 0.9f });
	help.setPosition({ 50.0f, -20.0f });
}

void Help::Draw(sf::RenderWindow* window)
{
	window->draw(help);
	back.Draw(window);
}

bool Help::CheckIfButtonWasClicked(sf::Vector2i vec)
{
	sf::Vector2f vecF = { (float)vec.x, (float)vec.y };

	return (back.rectangle.getGlobalBounds().contains(vecF.x, vecF.y));
};

void Help::SetFont(std::shared_ptr<MyFont> font)
{
	this->fontTitleText = font;
	back = Button("RETURN", 325.0f, 700.0f, font);
}