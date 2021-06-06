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
		std::shared_ptr<MyTexture> texturePtr;

		// Konstruktor parametryczny
		GameMode(std::shared_ptr<MyTexture> texturePtr);

		// Ustawia pozycje sprite'a
		void SetPosition(sf::Vector2f position);

		// Sprawdza czy sprite zosta³ klikniêty
		const bool IsClicked(sf::Vector2i& position) const;

		// Rysuje sprite'a
		void Draw(sf::RenderWindow* window);
	};

	std::vector<GameMode> modes;
	sf::Text text;
	std::shared_ptr<MyFont> fontPtr;

public:
	// Konstruktor domyœlny
	ModeSelectMenu();

	// Konstruktor parametryczny
	ModeSelectMenu(std::shared_ptr<MyFont> fontPtr);

	// Dodaje teksture oraz tworzy nowy obiekt GameMode'a
	// i dodaje go do wektora
	void AddTexture(std::shared_ptr<MyTexture> texturePtr);

	// Sprawdza, czy któryœ z GameModów zawartych w wektorze
	// zosta³ klikniêty
	const MyTexture::Type GetClickedMode(sf::Vector2i position) const;

	// Rysuje tekst oraz wszystkie elementy w wektorze GameMóde'ów
	void Draw(sf::RenderWindow* window);

private:
	// Ustawia wszystkie pozycje GameMode'ów w wektorze
	void SetUpGameModes();

	// Ustawia wszystkie propercje tekstu
	void SetUpText();
};
