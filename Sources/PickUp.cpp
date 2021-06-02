#include "..\Headers\PickUp.h"

PickUp::PickUp() : PickableItem() {}

PickUp::PickUp(float x, float y, std::shared_ptr<MyTexture> texturePtr)
	: PickableItem(x, y, texturePtr) {}