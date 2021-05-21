#pragma once
#include "Snake.h"
#include "PickUp.h"
#include "Background.h"
#include "TexturesManager.h"
#include "FontsManager.h"
#include "ScoreManager.h"
#include "LoseScreen.h"
#include "TypeInArea.h"
#include "HighScoreManager.h"
#include "Title.h"
#include "AudioManager.h"
#include "SnakeSelectMenu.h"

class GameManager
{
private:
	bool isPickUpCollected;
	bool isGameOver;
	bool isInSnakeSelect;

	Snake snake;
	PickUp pickUp;
	Background background;
	Title title;

	LoseScreen loseScreen;
	TypeInArea typeInArea;

	SnakeSelectMenu snakeSelectMenu;

	HighScoreManager highScoreManager;
	TexturesManager texturesManager;
	AudioManager audioManager;
	FontsManager fontsManager;
	ScoreManager scoreManager;

	std::vector<IDrawable*> drawableInGameObjects;
	std::vector<IDrawable*> drawableEndGameObjects;

public:
	// Podczas tworzenia obiektu ustawia wszystkie parametry swoich atrybutów
	GameManager();

	// Rysuje wszystkie rysowalne obiekty, które znajduj¹ siê w oknie podczas trwania gry
	// ¯eby narysowaæ obiekt, musi byæ zawarty w wektorze "drawableInGameObjects"
	void DrawInGameObjects(sf::RenderWindow* window);

	void DrawEndGameObjects(sf::RenderWindow* window);

	void DrawSnakeSelectMenu(sf::RenderWindow* window);

	// Porusza Snake'iem
	void MoveSnake();

	// Ustawia kierunek Snake'a
	void SetSnakeDirection(Snake::Direction direction);

	// Sprawdza obecne po³o¿enie snake'a : 
	// czy znajduje siê w arenie lub czy dosz³o do kolizji (czy zjad³ siebie)
	void CheckWhereIsSnake();

	// Sprawdza, czy PickUp zosta³ zebrany, jeœli tak: dodaje punkt
	// do score'a, zwiêksza wê¿a, generuje kolejny PickUp
	void CheckIfPickupIsCollected();

	void UpdateHighScores();

	void ResetGame();

	// Sprawdza czy gra siê skoñczy³a
	bool IsGameOver();

	bool IsInSnakeSelectMenu();

	void CheckIfSnakeWasSelected(sf::Vector2i position);

	// Zwraca obiekt klasy TextureManager
	const TexturesManager& GetTextureManager() const;

	// Zwraca obiekt klasy FontsManager
	const FontsManager& GetFontsManager() const;

	// Zwraca obiekt klasy ScoreManager
	const ScoreManager& GetScoreManager() const;

	// Zwraca obiekt klasy HighScoreManager
	const HighScoreManager& GetHighScoreManager() const;
	
	// Zwraca obiekt klasy AudiManager
	const AudioManager& GetAudioManager() const;

	// Zwraca obiekt kalsy TypeInAreaManager
	TypeInArea& GetTypeInAreaManager();

private:
	// Generuje PickUp'a 
	void GeneratePickUp();

	// Generowanie pocz¹tkowej pozycji snake'a
	void GenerateSnakePosition();
};