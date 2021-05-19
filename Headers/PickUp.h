#pragma once
#include <SFML/Graphics.hpp>
#include "Snake.h"

class PickUp
{
private:
	float posX;
	float posY;
	sf::RectangleShape shape;

	// Ustawia w³aœciwoœci PickUp'a
	void SetPickUpProperties();
public:
	// Konstruktor domyœlny
	PickUp();

	// Konstruktor parametryczny PickUp'a
	PickUp(float x, float y);

	// Rysuje PickUp'a w oknie gry
	void Draw(sf::RenderWindow* window);

	// Sprawdza, czy PickUp zosta³ zebrany
	bool IsCollected(Snake* snake);
};