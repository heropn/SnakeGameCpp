#include "..\Headers\ScoreManager.h"
#include <iostream>

ScoreManager::ScoreManager() : currentScore(0) {}

void ScoreManager::SetFont(std::shared_ptr<MyFont> fontPtr)
{
	this->fontPtr = fontPtr;
	SetUpText();
}

void ScoreManager::Draw(sf::RenderWindow* window)
{
	window->draw(text);
}

void ScoreManager::AddScore()
{
	currentScore += 10;
	text.setString(scoreStr + std::to_string(currentScore));
	auto rect = text.getLocalBounds();
	text.setOrigin(rect.width / 2, rect.height / 2);
	text.setPosition(500, 150);
}

int ScoreManager::GetScore()
{
	return currentScore;
}

void ScoreManager::ResetScore()
{
	currentScore = 0;
}

void ScoreManager::SetUpText()
{
	text.setFont(*fontPtr);
	text.setString(scoreStr + std::to_string(currentScore));
	text.setCharacterSize(50);
	text.setFillColor(sf::Color::White);
	auto rect = text.getLocalBounds();
	text.setOrigin(rect.width / 2, rect.height / 2);
	text.setPosition(500, 150);
}
