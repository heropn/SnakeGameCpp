#include "..\Headers\ScoreManager.h"

ScoreManager::ScoreManager() : currentScore(0), posX(500.0f), posY(190.0f) {}

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
	text.setPosition(posX, posY);
}

int ScoreManager::GetScore()
{
	return currentScore;
}

void ScoreManager::ResetScore()
{
	currentScore = 0;
	text.setString(scoreStr + std::to_string(currentScore));
	auto rect = text.getLocalBounds();
	text.setOrigin(rect.width / 2, rect.height / 2);
	text.setPosition(posX, posY);
}

void ScoreManager::SetUpText()
{
	text.setFont(*fontPtr);
	text.setString(scoreStr + std::to_string(currentScore));
	text.setCharacterSize(50);
	text.setFillColor(sf::Color::Color(118, 235, 0));
	auto rect = text.getLocalBounds();
	text.setOrigin(rect.width / 2, rect.height / 2);
	text.setPosition(posX, posY);
}

void ScoreManager::SubtractScore(int howMuchSubtractScore)
{
	if (currentScore - howMuchSubtractScore > 0)
	{
		currentScore -= howMuchSubtractScore;
	}
	else
	{
		currentScore = 0;
	}

	text.setString(scoreStr + std::to_string(currentScore));
	auto rect = text.getLocalBounds();
	text.setOrigin(rect.width / 2, rect.height / 2);
	text.setPosition(posX, posY);
}
