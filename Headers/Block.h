#pragma once
#include "PickableItem.h"

class Block : public PickableItem
{
public:
	// Konstruktor domyœlny
	Block();
	float x, y;
	// Konstruktor parametryczny PickUp'a
	Block(float x, float y, std::shared_ptr<MyTexture> texturePtr);
};