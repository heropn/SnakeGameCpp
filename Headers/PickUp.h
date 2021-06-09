#pragma once
#include "MapItem.h"

class PickUp : public MapItem
{
public:
	// Konstruktor domyœlny
	PickUp();

	// Konstruktor parametryczny PickUp'a
	// Wywo³uje konstruktor parametryczny dla MapItem
	PickUp(float x, float y, std::shared_ptr<MyTexture> texturePtr);
};