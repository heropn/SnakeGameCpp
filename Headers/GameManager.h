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
#include "PowerUpDisplayer.h"
#include "Block.h"
#include "ModeSelectMenu.h"

class GameManager
{
private:
	bool isPickUpCollected;
	bool isGameOver;
	bool isInSnakeSelect;
	bool isInModeSelect;
	bool isPowerUpCollected;
	bool isReversed;
	bool isPlayingClassicMode;

	int howManyBlocks;

	float snakeSpeedMultiplier;
	float timeBetweenPowerUps;
	float powerUpDuration;

	sf::Clock clock;
	sf::Clock durationTime;

	Snake snake;
	PickUp pickUp;
	PowerUp powerUp;

	std::vector<Block*> blocks;

	Background background;
	Title title;
	PowerUpDisplayer powerUpDisplayer;

	LoseScreen loseScreen;
	TypeInArea typeInArea;

	SnakeSelectMenu snakeSelectMenu;
	ModeSelectMenu modeSelectMenu;

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

	// Destruktror, usuwa wszystkie obiekty zalokowane dynamicznie
	~GameManager();

	// Rysuje wszystkie rysowalne obiekty, które znajduj¹ siê w oknie podczas trwania gry
	// ¯eby narysowaæ obiekt, musi byæ zawarty w wektorze "drawableInGameObjects"
	void DrawInGameObjects(sf::RenderWindow* window);

	// Rysuje obiekty znajduj¹cie siê na obrazie, który jest widoczny
	// podczas skoñczenia gry
	void DrawEndGameObjects(sf::RenderWindow* window);

	// Rysuje menu wyboru snake'a
	void DrawSnakeSelectMenu(sf::RenderWindow* window);

	// Rysuje menu wyboru trybu gry
	void DrawModeSelectMenu(sf::RenderWindow* window);

	// Porusza Snake'iem
	void MoveSnake();

	// Ustawia kierunek Snake'a
	void SetSnakeDirection(Snake::Direction direction);

	// Sprawdza obecne po³o¿enie snake'a : 
	// czy znajduje siê w arenie lub czy dosz³o do kolizji (czy zjad³ siebie)
	void CheckWhereIsSnake();

	// Sprawdza, czy PickUp lub PowerUp zosta³ zebrany, jeœli tak (PickUp): dodaje punkt
	// do score'a, zwiêksza wê¿a, generuje kolejny PickUp
	// Je¿eli PowerUp jest zebrany lub min¹³ okreœlony czas to generuje kolejny PowerUp
	void CheckIfPickupOrPowerUpIsCollected();

	//Sprawdza, czy czas Power Up'a siê skoñczy³, jeœli tak to wy³¹cza Power Up'a
	void CheckPowerUpDuration();

	// Wywo³uje u obiektów przeszkód metodê Flicker()
	void FlickerObjects();

	// Sprawdza, czy gra jest w trybie odwróconym (Góra->Dó³ , Lewo->Prawo)
	bool const IsReversed() const;

	// Daje Snake'owi okreœlony PowerUp
	void GiveSnakePower(PowerUp::UpgradeType upgradeType);

	// Odœwie¿a Highscora
	void UpdateHighScores();

	// Resetuje wszystkie parametry gry, aby mo¿na by³o j¹ zacz¹æ od nowa
	void ResetGame();

	// Sprawdza czy gra siê skoñczy³a
	bool IsGameOver();

	// Zwraca wartoœæ logiczn¹, czy gracz dalej znajduje siê w menu wyboru trybu
	bool IsInModeSelectMenu();

	// Zwraca wartoœæ logiczn¹, czy gracz dalej znajduje siê w menu wyboru snejka
	bool IsInSnakeSelectMenu();

	// Sprawdza czy snejk zosta³ wybrany przez gracza, jeœli tak
	// to ustawia go na domyœlnego w aktualnej grze
	void CheckIfSnakeWasSelected(sf::Vector2i position);

	// Sprawdza czy mode zosta³ wybrany przez gracza, jeœli tak
	// to ustawia go na domyœlnego w aktualnej grze
	void CheckIfModeWasSelected(sf::Vector2i position);

	// Zwraca obiekt klasy TextureManager
	const TexturesManager& GetTextureManager() const;

	// Zwraca obiekt klasy FontsManager
	const FontsManager& GetFontsManager() const;

	// Zwraca obiekt klasy ScoreManager
	const ScoreManager& GetScoreManager() const;

	// Zwraca obiekt klasy HighScoreManager
	HighScoreManager& GetHighScoreManager();
	
	// Zwraca obiekt klasy AudiManager
	AudioManager& GetAudioManager();

	// Zwraca obiekt klasy TypeInAreaManager
	TypeInArea& GetTypeInAreaManager();

	// Zwraca obiekt klasy SnakeSelectMenu
	SnakeSelectMenu& GetSnakeSelectMenu();

private:
	// Generuje PickUp'a 
	void GeneratePickUp();

	// Generuje Powerup'a jeœli up³yn¹³ odpowiedni czas
	void GeneratePowerUp();

	void GenerateBlock();

	// Generowanie pocz¹tkowej pozycji snake'a
	void GenerateSnakePosition();

	bool IsObjectOnBlock(float posX, float posY, sf::Vector2u pickUpSize, float additionalValue = 0.0f);

	// Wy³¹cza odpowiedniego Power Up'a
	void TurnOffPowerUp();

	// Ustawia grê w tryb odwrócony, gdy skrêcasz w prawo, jedziesz w lewo
	void SetReversion(bool val);
};