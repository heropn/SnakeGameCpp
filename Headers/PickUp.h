#pragma once
#include "PickableItem.h"

class PickUp : public PickableItem
{
public:
	// Konstruktor domyœlny
	PickUp();

	// Konstruktor parametryczny PickUp'a
	PickUp(float x, float y, std::shared_ptr<MyTexture> texturePtr);
};