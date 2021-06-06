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
	window->draw(infoText);
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
	titleText.setString("YOU LOST !");
	titleText.setCharacterSize(150);
	titleText.setFillColor(sf::Color::Color(0,179,11));
	auto rect = titleText.getLocalBounds();
	titleText.setOrigin(rect.width / 2, rect.height / 2);
	titleText.setPosition(500, 60);

	scoreText.setFont(*fontScore);
	scoreText.setString("Your score: 0");
	scoreText.setCharacterSize(70);
	scoreText.setFillColor(sf::Color::Color(25,255,142));
	rect = scoreText.getLocalBounds();
	scoreText.setOrigin(rect.width / 2, rect.height / 2);
	scoreText.setPosition(500, 210);

	infoText.setFont(*fontScore);
	infoText.setString("Click Enter to continue...");
	infoText.setCharacterSize(30);
	infoText.setFillColor(sf::Color::Color(78, 230, 18));
	rect = infoText.getLocalBounds();
	infoText.setOrigin(rect.width / 2, rect.height / 2);
	infoText.setPosition(500, 500);
}