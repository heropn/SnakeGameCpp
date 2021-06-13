#pragma once
#include <SFML/Graphics.hpp>
#include "MyFont.h"
#include "IDrawable.h"

class HighScoreEntity : public IDrawable
{
private:
	int score;
	sf::Text text;
	std::shared_ptr<MyFont> fontPtr;
	std::string name;

public:
	// Konstruktor parametryczny
	// Ustawia score, nazwe gracza oraz nazwe czcionki
	HighScoreEntity(int score, std::string name, std::shared_ptr<MyFont> fontPtr);

	// Ustawia pozycje tekstu
	void SetPosition(sf::Vector2f vec2);

	// Zwraca tekst
	const sf::Text& GetText() const;

	// Zwraca nazwê gracza
	const std::string& GetName() const;

	// Zwraca score gracza
	const int GetScore() const;

	// Ustawia aktualn¹ pozycje w rankingu
	void SetPositionInRanking(int position);

	// Rysuje tekst
	void Draw(sf::RenderWindow* window);

private:
	// Ustawia wszystkie parametry tekstu oraz ³aduje czcionkê
	void SetUpText();
};