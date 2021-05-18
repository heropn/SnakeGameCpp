#pragma once
#include "Snake.h"
#include "PickUp.h"
#include "Background.h"
#include <random>

class GameManager
{
private:
	Snake snake;
	bool isPickUpCollected;
	PickUp pickUp;
	Background background;
	bool isGameOver;
	int scores;
public:
	GameManager();
	void GenerateSnakePosition();
	void DrawSnake(sf::RenderWindow* window);
	void DrawBackground(sf::RenderWindow* window);
	void MoveSnake();
	void SetDirection(Snake::Direction direction);
	void IncreaseSnakesSize();
	void CheckWhereIsSnake();
	void GeneratePickUp();
	bool IsGameOver();
	void DrawPickUp(sf::RenderWindow* window);
	void CheckPickUp();
};