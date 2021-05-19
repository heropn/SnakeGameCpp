#include "..\Headers\HighScoreManager.h"
#include <fstream>
#include <iostream>

HighScoreManager::HighScoreManager() {}

HighScoreManager::HighScoreManager(std::shared_ptr<MyFont> fontTitleText, std::shared_ptr<MyFont> fontHighScores)
	: fontTitleText(fontTitleText), fontHighScores(fontHighScores)
{
	LoadScoresFromFile();
	SortHighScores();
	SetUpText();
}

void HighScoreManager::SetFonts(std::shared_ptr<MyFont> fontTitleText, std::shared_ptr<MyFont> fontHighScores)
{
	this->fontTitleText = fontTitleText;
	this->fontHighScores = fontHighScores;

	LoadScoresFromFile();
	SortHighScores();
	SetUpText();
}

void HighScoreManager::LoadScoresFromFile()
{
	std::ifstream file(pathToFile);
	std::string line;

	while (std::getline(file, line))
	{
		int index = line.find(' ');
		int number = std::stoi(line.substr(index));

		highScoreEntities.push_back(std::unique_ptr<HighScoreEntity>(new HighScoreEntity(number, line.substr(0, index), fontHighScores)));
	}
}

void HighScoreManager::AddHighScore(int score, std::string name)
{
	highScoreEntities.push_back(std::unique_ptr<HighScoreEntity>(new HighScoreEntity(score, name, fontHighScores)));
	SortHighScores();
}

void HighScoreManager::Draw(sf::RenderWindow* window)
{
	for (size_t i = 0; i < highScoreEntities.size(); i++)
	{
		highScoreEntities[i]->Draw(window);
	}

	window->draw(titleText);
}

HighScoreManager::~HighScoreManager()
{
	std::ofstream file(pathToFile);

	for (size_t i = 0; i < highScoreEntities.size(); i++)
	{
		file << highScoreEntities[i]->name + ' ' + std::to_string(highScoreEntities[i]->score) + '\n';
	}
}

void HighScoreManager::SetUpText()
{
	titleText.setFont(*fontTitleText);
	titleText.setString("HIGHSCORES");
	titleText.setCharacterSize(100);
	titleText.setFillColor(sf::Color::Red);
	auto rect = titleText.getLocalBounds();
	titleText.setOrigin(rect.width / 2, rect.height / 2);
	titleText.setPosition(500, 50);
}

void HighScoreManager::SortHighScores()
{
	std::sort(highScoreEntities.begin(), highScoreEntities.end(), HighScoreComparator);
	SetToMaxFiveHighScores();

	float posX = 300;
	float posY = 200;

	for (size_t i = 0; i < highScoreEntities.size(); i++)
	{
		highScoreEntities[i]->SetPositionInRanking(i + 1);
		highScoreEntities[i]->SetPosition({ posX, posY });
		posY += 100;
	}
}

bool HighScoreManager::HighScoreComparator(const std::unique_ptr<HighScoreEntity>& a, const std::unique_ptr<HighScoreEntity>& b)
{
	return a->score > b->score;
}

void HighScoreManager::SetToMaxFiveHighScores()
{
	if (highScoreEntities.size() > 5)
		highScoreEntities.erase(highScoreEntities.begin() + 5);
}