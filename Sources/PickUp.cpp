#include "..\Headers\PickUp.h"

PickUp::PickUp()
{
	posX = 500;
	posY = 500;
	SetPickUpProperties();
}

void PickUp::SetPickUpProperties()
{
	sf::RectangleShape shape(sf::Vector2f(20, 20));
	shape.setOrigin(sf::Vector2f(10, 10));
	shape.setFillColor(sf::Color::Yellow);
	shape.setPosition(sf::Vector2f(posX, posY));
	this->shape = shape;
}

PickUp::PickUp(int x, int y)
{
	posX = x;
	posY = y;
	SetPickUpProperties();
}

void PickUp::Draw(sf::RenderWindow* window)
{
	window->draw(shape);
}

bool PickUp::IsCollected(Snake* snake)
{
	sf::Vector2f position = shape.getPosition();
	sf::Vector2f size = shape.getSize();
	sf::Vector2f snakesPosition = snake->GetPosition();
	sf::Vector2u snakesSize = snake->GetSize();
	
	float topBorder = position.y - size.y / 2;
	float rightBorder = position.x + size.x / 2;
	float leftBorder = position.x - size.x / 2;
	float bottomBorder = position.y + size.y / 2;

	float snakesTopBorder = snakesPosition.y - (float)snakesSize.y / 2;
	float snakesrightBorder = snakesPosition.x + (float)snakesSize.x / 2;
	float snakesleftBorder = snakesPosition.x - (float)snakesSize.x / 2;
	float snakesbottomBorder = snakesPosition.y + (float)snakesSize.y / 2;

	if (bottomBorder > snakesTopBorder &&
		topBorder < snakesbottomBorder &&
		rightBorder > snakesleftBorder &&
		leftBorder < snakesrightBorder)
	{

		return true;
	}
	else 
		return false;
}