#include "..\Headers\Snake.h"
#include <iostream>

Snake::Snake() : posX(500.0f), posY(500.0f), size(1), speed(2.0f),
	increasingSize(10), direction(Direction::Left), immunited(false),
	isEatable(false), numberOfDecresedParts(0) {}

void Snake::SetSpriteProperties()
{
	sprite.setTexture(*headTexture);
	sprite.setOrigin(sf::Vector2f((float)headTexture->getSize().x / 2, (float)headTexture->getSize().y / 2));
	sprite.setPosition(sf::Vector2f(posX, posY));
}

void Snake::SetTextures(std::shared_ptr<MyTexture> headTexture, std::shared_ptr<MyTexture> bodyTexture)
{
	this->headTexture = headTexture;
	this->bodyTexture = bodyTexture;

	SetSpriteProperties();
	SetSpriteRotation();
}

void Snake::Draw(sf::RenderWindow* window)
{
	sprite.setTexture(*bodyTexture);

	// P�tla przechodzi przez vector positions i w zale�no�ci od d�ugo�ci snake'a ( ile pickup�w zebra�)
	// ustawia a nast�pnie wy�wietla sprite'a cia�a w�a
	for (unsigned int i = 1; i < size; i++)
	{
		if (positions.size() - 1 - i < 0 || positions.size() - 1 - i > positions.size())
			continue;

		sprite.setPosition(positions[positions.size() - 1 - i].x, positions[positions.size() - 1 - i].y);
		window->draw(sprite);
	}

	// Zostaje ustawiona pozycja sprite na aktualn� pozycje snake'a, czyli jego g�owe
	// a nast�pnie ustawiona zostaje tekstura g�owy snake'a
	sprite.setPosition(posX, posY);
	sprite.setTexture(*headTexture);
	window->draw(sprite);
}

void Snake::Move()
{
	if (direction == Direction::Top)
	{
		posY -= speed;
	}
	else if (direction == Direction::Right)
	{
		posX += speed;
	}
	else if (direction == Direction::Bottom)
	{
		posY += speed;
	}
	else if (direction == Direction::Left)
	{
		posX -= speed;
	}

	// Dodawana jest do vectora positions kolejna pozycja snake'a
	positions.push_back({ posX,posY });
}

void Snake::SetSpeed(float speed)
{
	this->speed = speed;
}

void Snake::SetDirection(Direction direction)
{
	// Sprawdzone zostaje, czy nast�pny kierunek snake'a nie jest przeciwny do poprzedniego kierunku
	if (!((this->direction == Direction::Bottom && direction == Direction::Top) ||
		(this->direction == Direction::Top && direction == Direction::Bottom) ||
		(this->direction == Direction::Left && direction == Direction::Right) ||
		(this->direction == Direction::Right && direction == Direction::Left)))
	{
		this->direction = direction;
		SetSpriteRotation();
	}
}

bool Snake::IsInArena(Background* background)
{
	sf::Vector2f position = background->GetShape().getPosition();
	sf::Vector2f size = background->GetShape().getSize();

	sf::Vector2f snakesPosition = GetPosition();
	sf::Vector2u snakesSize = GetSize();

	float topBorder = position.y - size.y / 2;
	float rightBorder = position.x + size.x / 2;
	float leftBorder = position.x - size.x / 2;
	float bottomBorder = position.y + size.y / 2;

	float snakesTopBorder = snakesPosition.y - (float)snakesSize.y / 2;
	float snakesrightBorder = snakesPosition.x + (float)snakesSize.x / 2;
	float snakesleftBorder = snakesPosition.x - (float)snakesSize.x / 2;
	float snakesbottomBorder = snakesPosition.y + (float)snakesSize.y / 2;

	if (snakesrightBorder <= rightBorder && snakesleftBorder >= leftBorder &&
		snakesTopBorder >= topBorder && snakesbottomBorder <= bottomBorder)
	{
		return true;
	}
	else
	{
		// Je�li snake wyjdzie poza arene, a ma w��czony Power Up pozwalajacy na przechodzenie przez obiekty
		// to przenie� snake'a na dok�adnie to samo miejsce, lecz z innej strony
		if (immunited)
		{
			if (snakesrightBorder > rightBorder)
			{
				SetPosition(snakesPosition.x - size.x + 15 ,snakesPosition.y);
			}

			if (snakesleftBorder < leftBorder)
			{
				SetPosition(snakesPosition.x + size.x - 15, snakesPosition.y);
			}

			if (snakesTopBorder < topBorder)
			{
				SetPosition(snakesPosition.x , snakesPosition.y + size.y - 15);
			}

			if (snakesbottomBorder > bottomBorder)
			{
				SetPosition(snakesPosition.x, snakesPosition.y - size.y + 15);
			}
		}
		return false;
	}
}

const sf::Sprite& Snake::GetSprite() const
{
	return sprite;
}

void Snake::Grow()
{
	if (positions.size() - (size + increasingSize) >= 0)
	{
		size += increasingSize;
	}
	else
	{
		size += (positions.size() - size);
	}

	speed += 0.2f;

	if (positions.size() > size)
	{
		positions.erase(positions.begin(), positions.end() - size);
	}
}

const sf::Vector2f& Snake::GetPosition() const
{
	if (positions.size() > 0)
	{
		return positions[positions.size() - 1];
	}
	else
	{
		return sprite.getPosition();
	}
}

bool Snake::IsCollision()
{
	for (unsigned int i = 10; i < size; i++)
	{
		if (positions.size() - 1 - i < 0 || positions.size() - 1 - i > positions.size())
			continue;

		if (abs(positions[positions.size() - 1].x - positions[positions.size() - 1 - i].x) < 5.0f &&
			abs(positions[positions.size() - 1].y - positions[positions.size() - 1 - i].y) < 5.0f)
		{
			// Je�li powsta�a kolizja, a snake ma w��czony Power Up pozwalaj�cy na jedzenie siebie
			// to zmniejsz jego rozmiar zale�ny od kt�rego elementu zosta� zjedzony
			if (isEatable)
			{
				numberOfDecresedParts = size - i;
				size -= size - i ;
				return true;
			}
			else
			{
				return true;
			}
		}
	}

	return false;
}

void Snake::Reset()
{
	size = 1;
	speed = 2.0f;
	positions.clear();
}

const sf::Vector2u Snake::GetSize() const
{
	if (headTexture != nullptr)
		return headTexture->getSize();
	else
		return {0, 0};
}

const Snake::Direction Snake::GetDirection() const
{
	return direction;
}

void Snake::SetPosition(float x, float y)
{
	posX = x;
	posY = y;
}

void Snake::SetSpriteRotation()
{
	if (direction == Direction::Top)
	{
		sprite.setRotation(0);
	}
	else if (direction == Direction::Right)
	{
		sprite.setRotation(90);
	}
	else if (direction == Direction::Bottom)
	{
		sprite.setRotation(180);
	}
	else
	{
		sprite.setRotation(270);
	}
}

bool Snake::IsObjectOnSnake(float posX, float posY, sf::Vector2u objSize, float additionalDistance)
{
	sf::Vector2u snakesSize = GetSize();

	float topBorder = 0;
	float rightBorder = 0;
	float leftBorder = 0;
	float bottomBorder = 0;

	float objectTopBorder = posY - ((float)objSize.y / 2) - additionalDistance;
	float objectRightBorder = posX + ((float)objSize.y / 2) + additionalDistance;
	float objectLeftBorder = posX - ((float)objSize.y / 2) - additionalDistance;
	float objectBottomBorder = posY + ((float)objSize.y / 2) + additionalDistance;

	for (unsigned int i = 0; i < size; i++)
	{
		if (positions.size() <= i)
		{
			if (i == 0)
			{
				topBorder = GetPosition().y - (float)snakesSize.y;
				rightBorder = GetPosition().x + (float)snakesSize.x;
				leftBorder = GetPosition().x - (float)snakesSize.x;
				bottomBorder = GetPosition().y + (float)snakesSize.y;

				if (objectTopBorder < bottomBorder &&
					objectBottomBorder > topBorder &&
					objectLeftBorder < rightBorder &&
					objectRightBorder > leftBorder)
				{
					return true;
				}
			}

			break;
		}

		topBorder = positions[i].y - (float)snakesSize.y;
		rightBorder = positions[i].x + (float)snakesSize.x;
		leftBorder = positions[i].x - (float)snakesSize.x;
		bottomBorder = positions[i].y + (float)snakesSize.y;

		if (objectTopBorder < bottomBorder &&
			objectBottomBorder > topBorder &&
			objectLeftBorder < rightBorder &&
			objectRightBorder > leftBorder)
		{
			return true;
		}
	}
	return false;
}

const float Snake::GetSpeed() const
{
	return speed;
}

void Snake::SetImmunization(bool val)
{
	immunited = val;
}

bool const Snake::IsImmunited() const
{
	return immunited;
}

void Snake::SetEatablility(bool val)
{
	isEatable = val;
}

const int Snake::GetNumberOfDecreasedParts() const
{
	return numberOfDecresedParts;
}

const bool Snake::IsEatable() const
{
	return isEatable;
}