#include "PickUp.h"

PickUp::PickUp()
{
	posX = 500;
	posY = 500;
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
	sf::Vector2f snakesPosition = snake->GetPosition();
	sf::Vector2f snakesSize = snake->GetShape().getSize();

	int snakesTopBorder = snakesPosition.y - snakesSize.y / 2;
	int snakesrightBorder = snakesPosition.x + snakesSize.x / 2;
	int snakesleftBorder = snakesPosition.x - snakesSize.x / 2;
	int snakesbottomBorder = snakesPosition.y + snakesSize.y / 2;

	if (posX >= snakesleftBorder && posX <= snakesrightBorder &&
		posY >= snakesTopBorder && posY<= snakesbottomBorder)
	{

		return true;
	}
	else return false;
}