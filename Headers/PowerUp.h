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
	// Konstruktor domyœlny
	PowerUp();

	// Konstruktor parametryczny PowerUp'a
	// Wywo³uje konstruktor parametryczny dla MapItem
	PowerUp(float x, float y, std::shared_ptr<MyTexture> texturePtr, UpgradeType type);

	// Zwraca typ Power Up'a
	const UpgradeType GetUpgradeType() const;

	// Zwraca poprzedni typ Power Up'a
	const UpgradeType GetPreviousType() const;

	// Ustawia typ pickupa na UpgradeType::None
	void SetNone();

	// Ustawia poprzedni typ w jakim by³ Power Up (potrzebne do wy³¹czania Power Up'a)
	void SetPreviousType(UpgradeType type);
};