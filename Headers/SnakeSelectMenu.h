#pragma once
#include <SFML/Graphics.hpp>
#include "MyTexture.h"
#include "IDrawable.h"
#include "MyFont.h"

class SnakeSelectMenu : public IDrawable
{
private:
	// Struktura trzymaj¹ca spirite'y g³ów Snake'a
	struct SnakeHead : public IDrawable
	{
		sf::Sprite sprite;
		std::shared_ptr<MyTexture> texturePtr;

		// Konstruktor parametryczny
		SnakeHead(std::shared_ptr<MyTexture> texturePtr);

		// Ustawia pozycje sprite'a
		void SetPosition(sf::Vector2f position);

		// Sprawdza czy sprite zosta³ klikniêty
		const bool IsMouseOnSprite(sf::Vector2i& position) const;

		// Rysuje sprite'a
		void Draw(sf::RenderWindow* window);
	};

	std::vector<SnakeHead> snakes;
	sf::Text text;
	std::shared_ptr<MyFont> fontPtr;

public:
	// Konstruktor domyœlny
	SnakeSelectMenu();

	// Konstruktor parametryczny
	// Ustawia czcionkê
	SnakeSelectMenu(std::shared_ptr<MyFont> fontPtr);

	// Dodaje teksture oraz tworzy nowy obiekt SnakeHead
	// i dodaje go do wektora
	void AddTexture(std::shared_ptr<MyTexture> texturePtr);

	// Sprawdza, czy któryœ z SnakeHead'ów zawartych w wektorze
	// zosta³ klikniêty
	const MyTexture::Type GetClickedSnake(sf::Vector2i position) const;

	// Zmienia kolor snejka, jeœli jest nad nim myszka
	void HighlightHoveredSnake(sf::Vector2i position);

	// Rysuje tekst oraz wszystkie elementy w wektorze SnakeHead'ów
	void Draw(sf::RenderWindow* window);

private:
	// Ustawia wszystkie pozycje SnakeHead'ów w wektorze
	void SetUpSnakes();

	// Ustawia wszystkie propercje tekstu
	void SetUpText();
};