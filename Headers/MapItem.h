#pragma once
#include <SFML/Graphics.hpp>
#include "Snake.h"
#include "IDrawable.h"
#include "MyTexture.h"

// G³ówna klasa przedmiotów, które w¹¿ mo¿e podnosiæ
class MapItem : public IDrawable
{
protected:
	float posX;
	float posY;
	std::shared_ptr<MyTexture> texturePtr;
	sf::Sprite sprite;

public:
	// Konstruktor domyœlny
	MapItem();

	// Konstuktor parametryczny
	MapItem(float x, float y, std::shared_ptr<MyTexture> texturePtr);

	// Rysuje sprite'a
	void Draw(sf::RenderWindow* window);

	// Zwraca wartoœæ, czy snake znajduje siê na przedmiocie, czy nie
	bool IsColliding(Snake* snake);

	// Zwraca rozmiar sprite'a
	const sf::Vector2u GetSize() const;

	// Zwraca wskaŸnik do tekstury 
	const std::shared_ptr<MyTexture> GetTexture() const;

protected:
	// Ustawia wszystkie parametry sprite'a
	void SetSpriteProperties();
};