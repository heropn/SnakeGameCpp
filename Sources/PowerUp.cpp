#include "..\Headers\PowerUp.h"

PowerUp::PowerUp() : PickableItem(), type(UpgradeType::None) {}

PowerUp::PowerUp(float x, float y, std::shared_ptr<MyTexture> texturePtr, UpgradeType type)
	: PickableItem(x, y, texturePtr), type(type) {}

const PowerUp::UpgradeType PowerUp::GetUpgradeType() const
{
	return type;
}

void PowerUp::SetNone()
{
	type = UpgradeType::None;
}