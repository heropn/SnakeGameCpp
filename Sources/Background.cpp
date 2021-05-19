#include "..\Headers\Background.h"

Background::Background()
{
	width = 800.0f;
	height = 500.0f;
	SetArenasProperties();
}

void Background::SetArenasProperties()
{
	sf::RectangleShape arena(sf::Vector2f(width, height));
	arena.setOrigin(sf::Vector2f(400.0f, 250.0f));
	arena.setFillColor(sf::Color::Transparent);
	arena.setOutlineThickness(10.0f);
	arena.setOutlineColor(sf::Color::White);
	arena.setPosition(sf::Vector2f(500.0f, 500.0f));
	this->arena = arena;
}

void Background::Draw(sf::RenderWindow* window)
{
	window->draw(arena);
}

const sf::RectangleShape& Background::GetShape() const
{
	return arena;
}
