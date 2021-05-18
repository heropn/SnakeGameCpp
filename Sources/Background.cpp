#include "..\Headers\Background.h"

Background::Background()
{
	width = 800;
	height = 500;
	SetArenasProperties();
}

void Background::SetArenasProperties()
{
	sf::RectangleShape arena(sf::Vector2f(width, height));
	arena.setOrigin(sf::Vector2f(400, 250));
	arena.setFillColor(sf::Color::Black);
	arena.setOutlineThickness(10);
	arena.setOutlineColor(sf::Color::White);
	arena.setPosition(sf::Vector2f(500, 500));
	this->arena = arena;
}

void Background::Draw(sf::RenderWindow* window)
{
	window->draw(arena);
}

sf::RectangleShape Background::GetShape()
{
	return arena;
}
