#pragma once
#include <iostream>
#include <string>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Button.h"
#include "IDrawable.h"
#include "Title.h"

using namespace std;

class MainMenu {
	Button *start, *highscore, *help, *credits, *quit;
	Title* snake;
	sf::RenderWindow* window;
public:
	MainMenu(sf::RenderWindow& win);
	void drawButtonsAndTitle();
	void checkIfButtonWasClicked(int x, int y);
};
