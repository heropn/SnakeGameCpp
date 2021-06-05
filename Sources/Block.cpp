#include "..\Headers\Block.h"

Block::Block() : PickableItem() {}

Block::Block(float x, float y, std::shared_ptr<MyTexture> texturePtr)
	: PickableItem(x, y, texturePtr) {
	this->x = x;
	this->y = y;
}