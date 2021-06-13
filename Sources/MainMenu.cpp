#include "../Headers/MainMenu.h"
#include <iostream>

MainMenu::MainMenu(sf::RenderWindow& win, std::shared_ptr<MyFont> fontPtrTitle,
	std::shared_ptr<MyFont> fontPtrButtons, std::shared_ptr<MyTexture> menuTexture,
	std::shared_ptr<MyTexture> creditsTexture, std::shared_ptr<MyTexture> helpTexture,
	std::shared_ptr<MyTexture> help2Texture, HighScoreManager* highScoreManagerPtr)
	: window(&win), fontPtrTitle(fontPtrTitle), fontPtrButtons(fontPtrButtons),
	isInMainMenu(true), currentMode(Mode::Default), texture(menuTexture),
	highScoreManagerPtr(highScoreManagerPtr)
{
	float x_offset = 550, y_offset_start = 250, y_offset = 100; //y_offset_start - startowe odsuniêcie od góry, y_offset - odstêp pomiêdzy kolejnymi przyciskami
	start = Button("PLAY", x_offset, y_offset_start, fontPtrButtons);
	highscore = Button("HIGHSCORES", x_offset, y_offset + y_offset_start, fontPtrButtons);
	help = Button("HELP", x_offset, 2 * y_offset + y_offset_start, fontPtrButtons);
	credits = Button("CREDITS", x_offset, 3 * y_offset + y_offset_start, fontPtrButtons);
	quit = Button("EXIT", x_offset, 4 * y_offset + y_offset_start, fontPtrButtons);

	creditsScreen.SetTexture(creditsTexture);
	helpScreen.SetTextures(helpTexture, help2Texture);
	snake.SetFont(fontPtrTitle);
	helpScreen.SetFont(fontPtrButtons);
	creditsScreen.SetFont(fontPtrButtons);
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
		highScoreManagerPtr->Draw(window);
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

	if (start.GetShape().getGlobalBounds().contains(vecF.x, vecF.y))
	{
		isInMainMenu = false;
	}
	else if (highscore.GetShape().getGlobalBounds().contains(vecF.x, vecF.y))
	{
		currentMode = Mode::HighScores;
		isInMainMenu = false;
	}
	else if (help.GetShape().getGlobalBounds().contains(vecF.x, vecF.y))
	{
		currentMode = Mode::Help;
		isInMainMenu = false;
	}
	else if (credits.GetShape().getGlobalBounds().contains(vecF.x, vecF.y))
	{
		currentMode = Mode::Credits;
		isInMainMenu = false;
	}
	else if (quit.GetShape().getGlobalBounds().contains(vecF.x, vecF.y))
	{
		window->close();
	}
}

void MainMenu::HighlightHoveredButton(sf::Vector2i vec)
{
	sf::Vector2f vecF = { (float)vec.x, (float)vec.y };

	if (start.GetShape().getGlobalBounds().contains(vecF.x, vecF.y))
	{
		start.SetHighlightColor();
	}
	else if (highscore.GetShape().getGlobalBounds().contains(vecF.x, vecF.y))
	{
		highscore.SetHighlightColor();
	}
	else if (help.GetShape().getGlobalBounds().contains(vecF.x, vecF.y))
	{
		help.SetHighlightColor();
	}
	else if (credits.GetShape().getGlobalBounds().contains(vecF.x, vecF.y))
	{
		credits.SetHighlightColor();
	}
	else if (quit.GetShape().getGlobalBounds().contains(vecF.x, vecF.y))
	{
		quit.SetHighlightColor();
	}
	else
	{
		start.SetDefaultColor();
		highscore.SetDefaultColor();
		help.SetDefaultColor();
		credits.SetDefaultColor();
		quit.SetDefaultColor();
	}

	highScoreManagerPtr->HiglightHoveredButton(vec);
	helpScreen.HiglightHoveredButton(vec);
	creditsScreen.HiglightHoveredButton(vec);
}

bool MainMenu::IsInMainMenu()
{
	return isInMainMenu;
}

void MainMenu::SetIsInMainMenu(bool value)
{
	isInMainMenu = value;
}
