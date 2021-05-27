#pragma once
#include <SFML/Graphics.hpp>
#include "Button.h"
#include "IDrawable.h"
#include "Title.h"
#include "HighScoreManager.h"
#include "MyTexture.h"

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

	std::shared_ptr<MyTexture> texture;
	sf::Sprite sprite;

	bool isInMainMenu;

	Mode currentMode;
public:
	MainMenu(sf::RenderWindow& win, std::shared_ptr<MyFont> fontPtrTitle, std::shared_ptr<MyFont> fontPtrButtons, std::shared_ptr<MyTexture> menuTexture);
	void DrawButtonsAndTitle();
	void CheckIfButtonWasClicked(sf::Vector2i vec);
	bool IsInMainMenu();
	void SetIsInMainMenu(bool value);

private:
	void SetSprite();
};
