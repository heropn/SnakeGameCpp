#pragma once
#include <SFML/Graphics.hpp>
#include "Button.h"
#include "IDrawable.h"
#include "Title.h"
#include "HighScoreManager.h"

class MainMenu 
{
private:
	enum class Mode
	{
		Default,
		HighScores,
		Credits,
		Help
	};

	Button start, highscore, help, credits, quit;
	Title snake;

	HighScoreManager highScoreManager;

	sf::RenderWindow* window;

	std::shared_ptr<MyFont> fontPtrTitle;
	std::shared_ptr<MyFont> fontPtrButtons;

	bool isInMainMenu;

	Mode currentMode;
public:
	MainMenu(sf::RenderWindow& win, std::shared_ptr<MyFont> fontPtrTitle, std::shared_ptr<MyFont> fontPtrButtons);
	void DrawButtonsAndTitle();
	void CheckIfButtonWasClicked(sf::Vector2i vec);
	virtual ~MainMenu();
	bool IsInMainMenu();
	void SetIsInMainMenu(bool value);
};
