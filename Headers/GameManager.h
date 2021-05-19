#pragma once
#include "Snake.h"
#include "PickUp.h"
#include "Background.h"
#include "TexturesManager.h"

class GameManager
{
private:
	int scores;
	bool isPickUpCollected;
	bool isGameOver;
	Snake snake;
	PickUp pickUp;
	Background background;
	TexturesManager texturesManager;

public:
	// Podczas tworzenia obiektu wygeneruje pocz¹tkowe po³o¿enie snake'a
	GameManager();

	// Generowanie pocz¹tkowej pozycji snake'a
	void GenerateSnakePosition();

	//DO ROBOTY
	void DrawSnake(sf::RenderWindow* window);

	//DO ROBOTY
	void DrawBackground(sf::RenderWindow* window);

	//DO ROBOTY
	void MoveSnake();

	//DO ROBOTY
	void SetDirection(Snake::Direction direction);

	// Sprawdza obecne po³o¿enie snake'a : 
	// czy znajduje siê w arenie lub czy dosz³o do kolizji (czy zjad³ siebie)
	void CheckWhereIsSnake();

	// Generuje PickUp'a 
	void GeneratePickUp();

	// Sprawdza czy gra siê skoñczy³a
	bool IsGameOver();

	//DO ROBOTY
	void DrawPickUp(sf::RenderWindow* window);

	// Sprawdza, czy PickUp zosta³ zebrany, jeœli tak: dodaje punkt
	// do score'a, zwiêksza wê¿a, generuje kolejny PickUp
	void CheckPickUp();
};