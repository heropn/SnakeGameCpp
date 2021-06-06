#include "..\Headers\Background.h"

Background::Background() : isBorderFlickering(false), timeBetweenFlickers(0.5f)
{
	width = 800.0f;
	height = 500.0f;
	SetArenasProperties();
}

void Background::Flicker()
{
	if (isBorderFlickering &&
		flickerClock.getElapsedTime().asSeconds() > timeBetweenFlickers * 2.0f)
	{
		flickerClock.restart();
	}
	else if (isBorderFlickering &&
		flickerClock.getElapsedTime().asSeconds() > timeBetweenFlickers)
	{
		border.setOutlineColor(sf::Color(101, 67, 33, 200));
	}
	else
	{
		border.setOutlineColor(sf::Color(101, 67, 33));
	}
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
	border.setSize({ width, height });
	border.setOrigin(sf::Vector2f(400.0f, 250.0f));
	border.setFillColor(sf::Color::Transparent);
	border.setOutlineThickness(10.0f);
	border.setOutlineColor(sf::Color(101, 67, 33));
	border.setPosition(sf::Vector2f(500.0f, 500.0f));
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

const bool Background::GetFlickerStatus() const
{
	return isBorderFlickering;
}

void Background::SetFlickerStatus(bool val)
{
	isBorderFlickering = val;
}
