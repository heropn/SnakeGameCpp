#include "..\Headers\PickUp.h"

PickUp::PickUp() : MapItem() {}

PickUp::PickUp(float x, float y, std::shared_ptr<MyTexture> texturePtr)
	: MapItem(x, y, texturePtr) {}