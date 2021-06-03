#pragma once
#include "PickableItem.h"

class PowerUp : public PickableItem
{
public:
	enum class UpgradeType
	{
		None,
		Speed,
		Slow,
		Immunity,
		Reversed,
		Eatable
	};

private:
	UpgradeType type;

public:
	// Konstruktor domyœlny
	PowerUp();

	// Konstruktor parametryczny PowerUp'a
	PowerUp(float x, float y, std::shared_ptr<MyTexture> texturePtr, UpgradeType type);

	// Zwraca typ Pickupa
	const UpgradeType GetUpgradeType() const;

	// Ustawia typ pickupa na UpgradeType::None
	void SetNone();
};