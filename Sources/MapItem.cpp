#include "..\Headers\MapItem.h"

MapItem::MapItem() : posX(500.0f), posY(500.0f) {}

void MapItem::SetSpriteProperties()
{
	sprite.setTexture(*texturePtr);
	sprite.setOrigin({ (float)texturePtr->getSize().x / 2, (float)texturePtr->getSize().y / 2 });
	sprite.setPosition(sf::Vector2f(posX, posY));
}

MapItem::MapItem(float x, float y, std::shared_ptr<MyTexture> texturePtr)
{
	this->texturePtr = texturePtr;
	posX = x;
	posY = y;
	SetSpriteProperties();
}

void MapItem::Draw(sf::RenderWindow* window)
{
	window->draw(sprite);
}

bool MapItem::IsColliding(Snake* snake)
{
	sf::Vector2f position = sprite.getPosition();
	sf::Vector2u size = texturePtr->getSize();
	sf::Vector2f snakesPosition = snake->GetPosition();
	sf::Vector2u snakesSize = snake->GetSize();

	float topBorder = position.y - (float)size.y / 2;
	float rightBorder = position.x + (float)size.x / 2;
	float leftBorder = position.x - (float)size.x / 2;
	float bottomBorder = position.y + (float)size.y / 2;

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

const sf::Vector2u MapItem::GetSize() const
{
	return texturePtr->getSize();
}

const std::shared_ptr<MyTexture> MapItem::GetTexture() const
{
	return texturePtr;
}