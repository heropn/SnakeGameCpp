#pragma once
#include "MapItem.h"

class Block : public MapItem
{
private:
	bool isFlickering;
	float timeBetweenFlickers;
	sf::Clock flickerClock;

public:
	// Konstruktor domyœlny
	Block();

	// Konstruktor parametryczny Block'a
	// Wywo³uje konstruktor parametryczny dla MapItem
	Block(float x, float y, std::shared_ptr<MyTexture> texturePtr);

	// Zwraca pozycje bloku
	const sf::Vector2f& GetPosition() const;

	// Sprawia,¿e alfa koloru sprite siê zmienia, 
	// gdy zmienna isFlickering jest ustawiona na true
	void Flicker();

	// Zwraca wartoœæ logiczn¹, czy Block miga
	const bool GetFlickerStatus() const;

	// Ustawia zmienn¹ isFlickering
	void SetFlickerStatus(bool val);
};