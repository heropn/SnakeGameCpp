#include "..\Headers\Background.h"

Background::Background()
{
	width = 800.0f;
	height = 500.0f;
	SetArenasProperties();
}

void Background::SetTextureAndSprite(std::shared_ptr<MyTexture> texturePtr)
{
	this->texturePtr = texturePtr;
	sprite.setTexture(*texturePtr);
	sprite.setOrigin({400.0f, 250.0f});
	sprite.setPosition(500.0f, 500.0f);
}

void Background::SetArenasProperties()
{
	sf::RectangleShape arena(sf::Vector2f(width, height));
	arena.setOrigin(sf::Vector2f(400.0f, 250.0f));
	arena.setFillColor(sf::Color::Transparent);
	arena.setOutlineThickness(10.0f);
	arena.setOutlineColor(sf::Color::Color(101, 67, 33));
	arena.setPosition(sf::Vector2f(500.0f, 500.0f));
	this->border = arena;
}

void Background::Draw(sf::RenderWindow* window)
{
	window->draw(border);
	window->draw(sprite);
}

const sf::RectangleShape& Background::GetShape() const
{
	return border;
}
