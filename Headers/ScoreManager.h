#pragma once
#include <SFML/Graphics.hpp>
#include "MyFont.h"
#include "IDrawable.h"

class ScoreManager : public IDrawable
{
private:
	sf::Text text;
	std::shared_ptr<MyFont> fontPtr;
	const std::string scoreStr = "Score: ";
	const std::string fontFilePath = "Fonts\\arial.ttf";
	int currentScore;
	float posX;
	float posY;
public:
	// Konstruktor domyœlny
	ScoreManager();

	// Ustawia dan¹ czcionkê na tekœcie
	void SetFont(std::shared_ptr<MyFont> fontPtr);

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
	void SetUpText();
};