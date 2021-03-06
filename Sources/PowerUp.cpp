#include "..\Headers\PowerUp.h"

PowerUp::PowerUp() : MapItem(), type(UpgradeType::None), previousType(UpgradeType::None) {}

PowerUp::PowerUp(float x, float y, std::shared_ptr<MyTexture> texturePtr, UpgradeType type)
	: MapItem(x, y, texturePtr), type(type), previousType(UpgradeType::None) {}

const PowerUp::UpgradeType PowerUp::GetUpgradeType() const
{
	return type;
}

const PowerUp::UpgradeType PowerUp::GetPreviousType() const
{
	return previousType;
}

void PowerUp::SetNone()
{
	type = UpgradeType::None;
}

void PowerUp::SetPreviousType(UpgradeType type)
{
	previousType = type;
}