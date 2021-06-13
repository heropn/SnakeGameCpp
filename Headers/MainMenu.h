#pragma once
#include <SFML/Graphics.hpp>
#include "Button.h"
#include "IDrawable.h"
#include "Title.h"
#include "HighScoreManager.h"
#include "MyTexture.h"
#include "Help.h"
#include "Credits.h"

class MainMenu 
{
public:
	enum class Mode
	{
		Default,
		HighScores,
		Credits,
		Help,
	};

private:

	Button start, highscore, help, credits, quit;
	Title snake;

	sf::RenderWindow* window;

	std::shared_ptr<MyFont> fontPtrTitle;
	std::shared_ptr<MyFont> fontPtrButtons;

	std::shared_ptr<MyTexture> texture;
	sf::Sprite sprite;

	bool isInMainMenu;

	Mode currentMode;

	Credits creditsScreen;
	Help helpScreen;
	HighScoreManager* highScoreManagerPtr;

public:
	// Konstruktor domyœlny, ustawia wszystkie zmienne, tekstury oraz czcionki
	// Tworzy odpowiednie Button'y
	MainMenu(sf::RenderWindow& win, std::shared_ptr<MyFont> fontPtrTitle,
		std::shared_ptr<MyFont> fontPtrButtons, std::shared_ptr<MyTexture> menuTexture,
		std::shared_ptr<MyTexture> creditsTexture, std::shared_ptr<MyTexture> helpTexture, std::shared_ptr<MyTexture> help2Texture,
		HighScoreManager* highScoreManagerPtr);

	// Rysuje odpowiednie obiekty na ekranie w zale¿noœci
	// Od tego w którym oknie menu gracz siê znajduje
	void Draw();

	// Sprawdza czy przycisk zosta³ klikniêty
	// Je¿eli tak wykonuje odpowiedni¹ akcjê
	void CheckIfButtonWasClicked(sf::Vector2i vec);

	// Zwraca true, jeœli gracz jest w menu g³ównym
	bool IsInMainMenu();

	// Ustawia zmienn¹ IsInMainMenu
	void SetIsInMainMenu(bool value);

	// Zwraca aktualny mode
	Mode GetCurrentMode();

	// Zwraca referencje do obiektu Credits
	Credits& GetCreditsScreen();

	// Zwraca referencje do obiektu Help
	Help& GetHelpScreen();

	// Zwraca pointer do obiektu HighScoreManager
	HighScoreManager* GetHighScoreManagerPtr();

	// Ustawia aktualny mode
	void SetCurrentMode(Mode mode);

	// Podœwietla przycisk jeœli jest nad nim myszka
	void HighlightHoveredButton(sf::Vector2i vec);

private:
	// Ustawia wszystkie w³asnoœci sprite'a
	void SetSprite();
};
