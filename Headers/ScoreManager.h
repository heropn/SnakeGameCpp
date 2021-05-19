#pragma once
#include <SFML/Graphics.hpp>

class ScoreManager
{
private:
	sf::Text text;
	sf::Font font;
	const std::string scoreStr = "Score: ";
	const std::string fontFilePath = "Fonts\\arial.ttf";
	int currentScore;
public:
	// Konstruktor domyœlny
	ScoreManager();

	// Rysuje tekst w oknie
	void Draw(sf::RenderWindow* window);

	// Dodaje punkty do aktualnego wyniku
	void AddScore();

	// Resetuje aktualny wynik
	void ResetScore();

	// Zwraca aktualny wynik
	int GetScore();

private:
	// £aduje czcionkê oraz ustaw wszystkie parametru zmiennej text
	void LoadFontAndSetText();
};