#pragma once
#include <iostream>
#include <string>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Button.h"
#include "IDrawable.h"
#include "Title.h"

using namespace std;

class MainMenu 
{
	Button start, highscore, help, credits, quit;
	Title snake;
	sf::RenderWindow* window;
	std::shared_ptr<MyFont> fontPtrTitle;
	std::shared_ptr<MyFont> fontPtrButtons;
	bool isInMainMenu;
public:
	MainMenu(sf::RenderWindow& win, std::shared_ptr<MyFont> fontPtrTitle, std::shared_ptr<MyFont> fontPtrButtons);
	void DrawButtonsAndTitle();
	void CheckIfButtonWasClicked(sf::Vector2i vec);
	virtual ~MainMenu();
	bool IsInMainMenu();
	void SetIsInMainMenu(bool value);
};
