#pragma once
#include <SFML/Graphics.hpp>
#include "HighScoreEntity.h"
#include "MyFont.h"

class HighScoreManager
{
private:
	const std::string pathToFile = "highscores.txt";
	std::shared_ptr<MyFont> fontTitleText;
	std::shared_ptr<MyFont> fontHighScores;
	sf::Text titleText;
	std::vector<std::unique_ptr<HighScoreEntity>> highScoreEntities;

public:
	// Konstruktor domyœlny
	HighScoreManager();

	// Konstruktor parametryczny
	HighScoreManager(std::shared_ptr<MyFont> fontTitleText, std::shared_ptr<MyFont> fontHighScores);

	// Dodaje nowy HighScore do tabeli
	void AddHighScore(int score, std::string name);

	// Rysuje ca³¹ tabelê najlepszych wyników, wraz z tytu³em
	void Draw(sf::RenderWindow* window);

	// Destruktor klay, zapisuje do pliku 5 najlepszych wyników
	virtual ~HighScoreManager();

private:
	// £aduje czionkê i ustawia wszystkie parametry tekstu
	void LoadFontAndSetText();

	// £aduje wszystkie wyniki z pliku
	void LoadScoresFromFile();

	// Sortuje wektor najlepszych wyników
	void SortHighScores();

	// Porównuje dwa wyniki pomiêdzy sob¹
	static bool HighScoreComparator(const std::unique_ptr<HighScoreEntity>& a, const std::unique_ptr<HighScoreEntity>& b);

	// Ustawia wielkoœæ wektora do maksymalnie 5
	void SetToMaxFiveHighScores();
};