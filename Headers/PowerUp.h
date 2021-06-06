#pragma once
#include "MapItem.h"

class PowerUp : public MapItem
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
	UpgradeType previousType;

public:
	// Konstruktor domy�lny
	PowerUp();

	// Konstruktor parametryczny PowerUp'a
	PowerUp(float x, float y, std::shared_ptr<MyTexture> texturePtr, UpgradeType type);

	// Zwraca typ Pickupa
	const UpgradeType GetUpgradeType() const;

	const UpgradeType GetPreviousType() const;

	// Ustawia typ pickupa na UpgradeType::None
	void SetNone();

	void SetPreviousType(UpgradeType type);
};