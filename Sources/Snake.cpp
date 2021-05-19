#include "..\Headers\Snake.h"

Snake::Snake() : 
	posX(0.0f), posY(0.0f), size(0.0f), speed(0), direction(Direction::Left) {}

Snake::Snake(std::shared_ptr<MyTexture> headTexture, std::shared_ptr<MyTexture> bodyTexture) : headTexture(headTexture), bodyTexture(bodyTexture)
{
	posX = 500.0f;
	posY = 500.0f;
	speed = 1.0f;
	size = 1;
	direction = Direction::Left;
	SetSpriteProperties();
	SetSpriteRotation();
}

void Snake::SetSpriteProperties()
{
	sprite.setTexture(*headTexture);
	sprite.setOrigin(sf::Vector2f((float)headTexture->getSize().x / 2, (float)headTexture->getSize().y / 2));
	sprite.setPosition(sf::Vector2f(posX, posY));
}

void Snake::Draw(sf::RenderWindow* window)
{
	sprite.setTexture(*bodyTexture);
	for (unsigned int i = 1; i < size; i++)
	{
		sprite.setPosition(positions[positions.size() - 1 - i].x, positions[positions.size() - 1 - i].y);
		window->draw(sprite);
	}

	sprite.setPosition(positions[positions.size() - 1].x, positions[positions.size() - 1].y);
	sprite.setTexture(*headTexture);
	window->draw(sprite);
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
}

void Snake::SetSpeed(float speed)
{
	this->speed = speed;
}

void Snake::SetDirection(Direction direction)
{
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
	sf::Vector2u snakesSize = headTexture->getSize();

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
		return false;
	}
}

const sf::Sprite& Snake::GetSprite() const
{
	return sprite;
}

void Snake::Grow()
{
	if (positions.size() - (size + 10) >= 0)
	{
		size += 10;
	}
	else
	{
		size += (positions.size() - size);
	}

	speed += 0.05f;

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
	for (unsigned int i = 1; i < size; i++)
	{
		if (abs(positions[positions.size() - 1].x - positions[positions.size() - 1 - i].x) < 1 &&
			abs(positions[positions.size() - 1].y - positions[positions.size() - 1 - i].y) < 1)
		{
			return true;
		}
	}
	return false;
}

const sf::Vector2u Snake::GetSize() const
{
	return headTexture->getSize();
}

const Snake::Direction Snake::GetDirection() const
{
	return direction;
}

void Snake::SetPosition(float x, float y)
{
	sprite.setPosition({ x, y });
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