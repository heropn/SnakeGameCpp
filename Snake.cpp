#include "Snake.h"
//#include <iostream>
Snake::Snake()
{
	posX = 500;
	posY = 500;
	speed = 1;
	size = 0;
	direction = Direction::Left;
}
//ustawia w³aœciwoœci snake'a
void Snake::SetSnakesProperties()
{
	shape.setSize(sf::Vector2f(30, 30));
	shape.setOrigin(sf::Vector2f(15, 15));
	shape.setFillColor(sf::Color::Green);
	shape.setPosition(sf::Vector2f(posX, posY));
}

// podczas tworzenia obiektu w konstuktorze parametrycznym zostaj¹ przypisane atrybuty 
// odpowiadaj¹ce za pozycjê snake'a oraz ustawione zostaj¹ w³aœciwoœci snake'a

Snake::Snake(float x, float y,Direction direction)
{
	posX = x;
	posY = y;
	speed = 2;
	size = 1;
	this->direction = direction;
	SetSnakesProperties();
}

//rysuje snake'a na ekranie
void Snake::Draw(sf::RenderWindow* window)
{
	shape.setFillColor(sf::Color::Green);
	for (int i = 1; i < size-1; i++)
	{
		shape.setPosition(positions[positions.size() - 1 - i].x, positions[positions.size() - 1 - i].y);
		window->draw(shape);
	}

	shape.setPosition(positions[positions.size() - 1].x, positions[positions.size() - 1].y);
	shape.setFillColor(sf::Color::Red);
	window->draw(shape);

	if (positions.size() > size)
	{
		positions.erase(positions.begin(), positions.end() - size);
	}
}

void Snake::Move()
{
	if (direction == Direction::Top)
	{
		posY -= 1 * speed;
	}
	else if (direction == Direction::Right)
	{
		posX += 1 * speed;
	}
	else if (direction == Direction::Bottom)
	{
		posY += 1 * speed;
	}
	else if (direction == Direction::Left)
	{
		posX -= 1 * speed;
	}
	positions.push_back({ posX,posY });
	//std::cout << posX << " " << posY << std::endl;
}

void Snake::SetSpeed(int speed)
{
	this->speed = speed;
}

//zmiana kierunku poruszania siê snake'a
void Snake::SetDirection(Direction direction)
{
	if (!((this->direction == Direction::Bottom && direction == Direction::Top) ||
		(this->direction == Direction::Top && direction == Direction::Bottom) ||
		(this->direction == Direction::Left && direction == Direction::Right) ||
		(this->direction == Direction::Right && direction == Direction::Left)))
	{
		this->direction = direction;
	}
}

//funkcja sprawdza, czy Snake znajduje siê w polu gry
bool Snake::IsInArena(Background* background)
{
	sf::Vector2f position = background->GetShape().getPosition();
	sf::Vector2f size = background->GetShape().getSize();

	sf::Vector2f snakesPosition = GetPosition();
	sf::Vector2f snakesSize = shape.getSize();

	int topBorder = position.y - size.y / 2;
	int rightBorder = position.x + size.x / 2;
	int leftBorder = position.x - size.x / 2;
	int bottomBorder = position.y + size.y / 2;

	int snakesTopBorder = snakesPosition.y - snakesSize.y / 2;
	int snakesrightBorder = snakesPosition.x + snakesSize.x / 2;
	int snakesleftBorder = snakesPosition.x - snakesSize.x / 2;
	int snakesbottomBorder = snakesPosition.y + snakesSize.y / 2;

	if (snakesrightBorder <= rightBorder && snakesleftBorder >= leftBorder &&
		snakesTopBorder >= topBorder && snakesbottomBorder <= bottomBorder)
	{
		return true;
	}
	else
	{
		return false;
	}
}
sf::RectangleShape Snake::GetShape()
{
	return shape;
}

void Snake::Grow()
{
	size++;
	speed += 0.1;
}

sf::Vector2f Snake::GetPosition()
{
	if (positions.size() > 0)
	{
		return positions[positions.size() - 1];
	}
	else
	{
		return shape.getPosition();
	}
}

bool Snake::IsCollision()
{
	for (int i = 1; i < size; i++)
	{
		if (posX == positions[positions.size() - 1 - i].x && posY == positions[positions.size() - 1 - i].y)
		{
			return true;
		}
	}
	return false;
}