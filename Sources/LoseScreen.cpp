#include "..\Headers\LoseScreen.h"

LoseScreen::LoseScreen() {}

LoseScreen::LoseScreen(std::shared_ptr<MyFont> fontTitle, std::shared_ptr<MyFont> fontScore)
	: fontTitle(fontTitle), fontScore(fontScore)
{
	SetUpTextes();
}

void LoseScreen::Draw(sf::RenderWindow* window)
{
	window->draw(titleText);
	window->draw(scoreText);
}

void LoseScreen::SetScore(int score)
{
	scoreText.setString("Your score: " + std::to_string(score));
	auto rect = scoreText.getLocalBounds();
	scoreText.setOrigin(rect.width / 2, rect.height / 2);
	scoreText.setPosition(500, 200);
}

void LoseScreen::SetUpTextes()
{
	titleText.setFont(*fontTitle);
	titleText.setString("YOU LOST!");
	titleText.setCharacterSize(100);
	titleText.setFillColor(sf::Color::Red);
	auto rect = titleText.getLocalBounds();
	titleText.setOrigin(rect.width / 2, rect.height / 2);
	titleText.setPosition(500, 50);

	scoreText.setFont(*fontScore);
	scoreText.setString("Your score: 0");
	scoreText.setCharacterSize(70);
	scoreText.setFillColor(sf::Color::Red);
	rect = scoreText.getLocalBounds();
	scoreText.setOrigin(rect.width / 2, rect.height / 2);
	scoreText.setPosition(500, 200);
}