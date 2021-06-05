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
#include "PowerUp.h"

class GameManager
{
private:
	bool isPickUpCollected;
	bool isGameOver;
	bool isInSnakeSelect;
	bool isPowerUpCollected;
	bool isReversed;

	float snakeSpeedMultiplier;
	float timeBetweenPowerUps;
	float powerUpDuration;

	sf::Clock clock;
	sf::Clock durationTime;

	Snake snake;
	PickUp pickUp;
	PowerUp powerUp;
	

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

	// Rysuje obiekty znajduj¹cie siê na obrazie, który jest widoczny
	// podczas skoñczenia gry
	void DrawEndGameObjects(sf::RenderWindow* window);

	// Rysuje menu wyboru snake'a
	void DrawSnakeSelectMenu(sf::RenderWindow* window);

	// Porusza Snake'iem
	void MoveSnake();

	// Ustawia kierunek Snake'a
	void SetSnakeDirection(Snake::Direction direction);

	// Sprawdza obecne po³o¿enie snake'a : 
	// czy znajduje siê w arenie lub czy dosz³o do kolizji (czy zjad³ siebie)
	void CheckWhereIsSnake();

	// Sprawdza, czy PickUp lub PowerUp zosta³ zebrany, jeœli tak (PickUp): dodaje punkt
	// do score'a, zwiêksza wê¿a, generuje kolejny PickUp
	// Je¿eli PowerUp jest zebrany i min¹³ okreœlony czas to generuje kolejny PowerUp
	void CheckIfPickupOrPowerUpIsCollected();

	void CheckPowerUpDuration();

	bool const IsReversed() const;

	void TurnOffPowerUp();

	void SetReversion();

	void TurnOffReversion();

	void FlickerBorder();

	// Daje Snake'owi okreœlony PowerUp
	void GiveSnakePower(PowerUp::UpgradeType upgradeType);

	// Odœwie¿a Highscora
	void UpdateHighScores();

	// Resetuje wszystkie parametry gry, aby mo¿na by³o j¹ zacz¹æ od nowa
	void ResetGame();

	// Sprawdza czy gra siê skoñczy³a
	bool IsGameOver();

	// Zwraca wartoœæ logiczn¹, czy gracz dalej znajduje siê w menu wyboru snejka
	bool IsInSnakeSelectMenu();

	// Sprawdza czy snejk zosta³ wybrany przez gracza, jeœli tak
	// to ustawia go na domyœlnego w aktualnej grze
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

	// Generuje Powerup'a jeœli up³yn¹³ odpowiedni czas
	void GeneratePowerUp();

	// Generowanie pocz¹tkowej pozycji snake'a
	void GenerateSnakePosition();
};