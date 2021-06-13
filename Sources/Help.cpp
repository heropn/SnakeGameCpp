#include "..\Headers\Help.h"

Help::Help() {}

void Help::SetTexture(std::shared_ptr<MyTexture> texture)
{
	helpTexture = texture;
	help.setTexture(*helpTexture);
	help.setScale({ 0.9f, 0.9f });
	help.setPosition({ 50.0f, -20.0f });
}

void Help::Draw(sf::RenderWindow* window, const std::string& which_page)
{
	window->draw(help);
	back.Draw(window);
	if (which_page == "first")
		next_page.Draw(window);
	else
		prev_page.Draw(window);
}

bool Help::CheckIfReturnButtonWasClicked(sf::Vector2i vec)
{
	sf::Vector2f vecF = { (float)vec.x, (float)vec.y };

	return (back.rectangle.getGlobalBounds().contains(vecF.x, vecF.y));
}

bool Help::CheckIfNextPageButtonWasClicked(sf::Vector2i vec)
{
	sf::Vector2f vecF = { (float)vec.x, (float)vec.y };

	return (next_page.rectangle.getGlobalBounds().contains(vecF.x, vecF.y));
}

bool Help::CheckIfPrevPageButtonWasClicked(sf::Vector2i vec)
{
	sf::Vector2f vecF = { (float)vec.x, (float)vec.y };

	return (prev_page.rectangle.getGlobalBounds().contains(vecF.x, vecF.y));
}

void Help::SetFont(std::shared_ptr<MyFont> font)
{
	this->fontTitleText = font;
	back = Button("RETURN", 50.0f, 700.0f, font);
	next_page = Button("NEXT PAGE", 600.0f, 700.0f, font);
	prev_page = Button("FIRST PAGE", 600.0f, 700.0f, font);
}