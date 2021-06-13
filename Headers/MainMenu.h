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
	MainMenu(sf::RenderWindow& win, std::shared_ptr<MyFont> fontPtrTitle,
		std::shared_ptr<MyFont> fontPtrButtons, std::shared_ptr<MyTexture> menuTexture,
		std::shared_ptr<MyTexture> creditsTexture, std::shared_ptr<MyTexture> helpTexture, std::shared_ptr<MyTexture> help2Texture,
		HighScoreManager* highScoreManagerPtr);
	void DrawButtonsAndTitle();
	void CheckIfButtonWasClicked(sf::Vector2i vec);
	bool IsInMainMenu();
	void SetIsInMainMenu(bool value);

	Mode GetCurrentMode();

	Credits& GetCreditsScreen();

	Help& GetHelpScreen();

	HighScoreManager* GetHighScoreManagerPtr();

	void SetCurrentMode(Mode mode);

	// Podœwietla przycisk jeœli jest nad nim myszka
	void HighlightHoveredButton(sf::Vector2i vec);

private:
	void SetSprite();
};
