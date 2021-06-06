#include "..\Headers\Block.h"

Block::Block() : MapItem() {}

Block::Block(float x, float y, std::shared_ptr<MyTexture> texturePtr)
	: MapItem(x, y, texturePtr) {}

const sf::Vector2f& Block::GetPosition() const
{
	return sprite.getPosition();
}