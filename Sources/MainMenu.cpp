#include "../Headers/MainMenu.h"
#include <iostream>

MainMenu::MainMenu(sf::RenderWindow& win, std::shared_ptr<MyFont> fontPtrTitle, std::shared_ptr<MyFont> fontPtrButtons, std::shared_ptr<MyTexture> menuTexture)
	: window(&win), fontPtrTitle(fontPtrTitle), fontPtrButtons(fontPtrButtons), isInMainMenu(true), currentMode(Mode::Default), texture(menuTexture)
{
	float x_offset = 550, y_offset_start = 250, y_offset = 100; //y_offset_start - startowe odsuniêcie od góry, y_offset - odstêp pomiêdzy kolejnymi przyciskami
	start = Button("PLAY", x_offset, y_offset_start, fontPtrButtons);
	highscore = Button("HIGHSCORES", x_offset, y_offset + y_offset_start, fontPtrButtons);
	help = Button("HELP", x_offset, 2 * y_offset + y_offset_start, fontPtrButtons);
	credits = Button("CREDITS", x_offset, 3 * y_offset + y_offset_start, fontPtrButtons);
	quit = Button("EXIT", x_offset, 4 * y_offset + y_offset_start, fontPtrButtons);

	snake.SetFont(fontPtrTitle);
	highScoreManager.SetFonts(fontPtrTitle, fontPtrButtons);
	helpScreen.setFont(fontPtrTitle);
	creditsScreen.setFont(fontPtrTitle);
	SetSprite();
}

void MainMenu::SetSprite()
{
	sprite.setTexture(*texture);
}

void MainMenu::DrawButtonsAndTitle() 
{
	if (currentMode == Mode::Default)
	{
		window->draw(sprite);
		snake.Draw(window);
		start.Draw(window);
		highscore.Draw(window);
		help.Draw(window);
		credits.Draw(window);
		quit.Draw(window);
	}
	else if (currentMode == Mode::HighScores)
	{
		highScoreManager.Draw(window);
	}
	else if (currentMode == Mode::Credits)
	{
		creditsScreen.Draw(window);
	}
	else if (currentMode == Mode::Help)
	{
		helpScreen.Draw(window);
	}
}

void MainMenu::CheckIfButtonWasClicked(sf::Vector2i vec)
{
	sf::Vector2f vecF = { (float)vec.x, (float)vec.y };

	if (start.rectangle.getGlobalBounds().contains(vecF.x, vecF.y))
	{
		std::cout << "Graj" << std::endl;
		isInMainMenu = false;
	}
	else if (highscore.rectangle.getGlobalBounds().contains(vecF.x, vecF.y))
	{
		std::cout << "Najlepsze wyniki" << std::endl;
		currentMode = Mode::HighScores;
		isInMainMenu = false;
	}
	else if (help.rectangle.getGlobalBounds().contains(vecF.x, vecF.y))
	{
		std::cout << "Pomoc" << std::endl;
		currentMode = Mode::Help;
		isInMainMenu = false;
	}
	else if (credits.rectangle.getGlobalBounds().contains(vecF.x, vecF.y))
	{
		std::cout << "Creditsy" << std::endl;
		currentMode = Mode::Credits;
		isInMainMenu = false;
	}
	else if (quit.rectangle.getGlobalBounds().contains(vecF.x, vecF.y))
	{
		std::cout << "Exit" << std::endl;
		window->close();
	}
};

bool MainMenu::IsInMainMenu()
{
	return isInMainMenu;
}

void MainMenu::SetIsInMainMenu(bool value)
{
	isInMainMenu = value;
}
