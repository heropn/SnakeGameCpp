#pragma once
#include <SFML/Graphics.hpp>
#include "Snake.h"

class PickUp
{
private:
	int posX;
	int posY;
	sf::RectangleShape shape;
	void SetPickUpProperties();
public:
	PickUp();
	PickUp(int x, int y);
	void Draw(sf::RenderWindow* window);
	bool IsCollected(Snake* snake);
};