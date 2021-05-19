#pragma once
#include "Snake.h"
#include "PickUp.h"
#include "Background.h"
#include "TexturesManager.h"
#include "FontsManager.h"
#include "ScoreManager.h"

class GameManager
{
private:
	bool isPickUpCollected;
	bool isGameOver;

	Snake snake;
	PickUp pickUp;
	Background background;
	TexturesManager texturesManager;
	FontsManager fontsManager;
	ScoreManager scoreManager;

	std::vector<IDrawable*> drawableInGameObjects;

public:
	// Podczas tworzenia obiektu ustawia wszystkie parametry swoich atrybutów
	GameManager();

	// Rysuje wszystkie rysowalne obiekty, które znajduj¹ siê w oknie podczas trwania gry
	// ¯eby narysowaæ obiekt, musi byæ zawarty w wektorze "drawableInGameObjects"
	void DrawInGameObjects(sf::RenderWindow* window);

	// Porusza Snake'iem
	void MoveSnake();

	// Ustawia kierunek Snake'a
	void SetSnakeDirection(Snake::Direction direction);

	// Sprawdza obecne po³o¿enie snake'a : 
	// czy znajduje siê w arenie lub czy dosz³o do kolizji (czy zjad³ siebie)
	void CheckWhereIsSnake();

	// Sprawdza, czy PickUp zosta³ zebrany, jeœli tak: dodaje punkt
	// do score'a, zwiêksza wê¿a, generuje kolejny PickUp
	void CheckPickUp();

	// Sprawdza czy gra siê skoñczy³a
	bool IsGameOver();

	// Zwraca obiekt klasy TextureManager
	const TexturesManager& GetTextureManager() const;

	// Zwraca obiekt klasy FontsManager
	const FontsManager& GetFontsManager() const;

	// Zwraca obiekt klasy ScoreManager
	const ScoreManager& GetScoreManager() const;

private:
	// Generuje PickUp'a 
	void GeneratePickUp();

	// Generowanie pocz¹tkowej pozycji snake'a
	void GenerateSnakePosition();
};