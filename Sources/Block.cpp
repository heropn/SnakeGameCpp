#include "..\Headers\Block.h"

Block::Block() : MapItem(), isFlickering(false), timeBetweenFlickers(0.5f) {}

Block::Block(float x, float y, std::shared_ptr<MyTexture> texturePtr)
	: MapItem(x, y, texturePtr), isFlickering(false), timeBetweenFlickers(0.5f) {}

const sf::Vector2f& Block::GetPosition() const
{
	return sprite.getPosition();
}

void Block::Flicker()
{
	if (isFlickering &&
		flickerClock.getElapsedTime().asSeconds() > timeBetweenFlickers * 2.0f)
	{
		flickerClock.restart();
	}
	else if (isFlickering &&
		flickerClock.getElapsedTime().asSeconds() > timeBetweenFlickers)
	{
		sprite.setColor({ 255, 255, 255, 150 });
	}
	else
	{
		sprite.setColor({ 255, 255, 255 });
	}
}

const bool Block::GetFlickerStatus() const
{
	return isFlickering;
}

void Block::SetFlickerStatus(bool val)
{
	isFlickering = val;
}