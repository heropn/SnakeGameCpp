#pragma once
#include <SFML/Graphics.hpp>
#include "IDrawable.h"
#include "MyTexture.h"
#include "MyFont.h"

class ModeSelectMenu : public IDrawable
{
private:
	// Struktura trzymaj¹ca spirite'y g³ów Snake'a
	struct GameMode : public IDrawable
	{
		sf::Sprite sprite;
		sf::Text text;
		std::shared_ptr<MyTexture> texturePtr;
		std::shared_ptr<MyFont> fontPtr;

		// Konstruktor parametryczny, ustawia odpowiedni¹ teksturê oraz
		// Czcionkê tekstu pod sprite'm
		GameMode(std::shared_ptr<MyTexture> texturePtr, std::shared_ptr<MyFont> fontPtr);

		// Ustawia pozycje sprite'a
		void SetPosition(sf::Vector2f position);

		// Sprawdza czy sprite zosta³ klikniêty
		const bool IsMouseOnGameMode(sf::Vector2i& position) const;

		// Rysuje sprite'a
		void Draw(sf::RenderWindow* window);

		void SetUpText(const std::string& str);
	};

	std::vector<GameMode> modes;
	sf::Text text;
	std::shared_ptr<MyFont> fontTitle;
	std::shared_ptr<MyFont> fontDescription;

public:
	// Konstruktor domyœlny
	ModeSelectMenu();

	// Konstruktor parametryczny
	// Ustawia czcionkê tytu³u oraz czcionkê pod teksturami trybów
	ModeSelectMenu(std::shared_ptr<MyFont> fontPtr, std::shared_ptr<MyFont> descFontPtr);

	// Dodaje teksture oraz tworzy nowy obiekt GameMode'a
	// i dodaje go do wektora
	void AddTexture(std::shared_ptr<MyTexture> texturePtr);

	// Sprawdza, czy któryœ z GameModów zawartych w wektorze
	// zosta³ klikniêty
	const MyTexture::Type GetClickedMode(sf::Vector2i position) const;

	// Zmienia kolor mode'u, jeœli jest nad nim myszka
	void HighlightHoveredMode(sf::Vector2i position);

	// Rysuje tekst oraz wszystkie elementy w wektorze GameMóde'ów
	void Draw(sf::RenderWindow* window);

private:
	// Ustawia wszystkie pozycje GameMode'ów w wektorze
	void SetUpGameModes();

	// Ustawia wszystkie propercje tekstu
	void SetUpText();
};
