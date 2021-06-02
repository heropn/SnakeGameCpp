#pragma once
#include <SFML/Graphics.hpp>
#include "MyFont.h"
#include "IDrawable.h"

class TypeInArea : public IDrawable
{
private:
	sf::String playerInput;
	sf::Text displayText;
	sf::Text topText;
	std::shared_ptr<MyFont> fontDisplayText;
	std::shared_ptr<MyFont> fontTopText;
	sf::RectangleShape rectangle;

public:
	// Konstruktor domyœlny
	TypeInArea();

	// Konstruktor parametryczny
	TypeInArea(std::shared_ptr<MyFont> fontDisplayText, std::shared_ptr<MyFont> fontTopText);

	// Aktualizuje aktualn¹ nazwê gracza
	void UpdateText(sf::String str);

	// Usuwa ostatni znak z nazwy gracza
	void EreseLastCharacter();

	// Rysuje ca³e pole do wpisywania
	void Draw(sf::RenderWindow* window);

	void GetPlayerInput(char c);

	// Zwraca nazwe gracza
	const std::string GetPlayerName() const;

	//Resetuje parametry TypeInArea'i
	void Reset();

private:
	// £aduje czcionkê i ustawia wszystkie parametry obu tekstów
	void SetUpTextes();

	// Ustawia wszystkie paramertry prostok¹ta
	void SetUpRectangle();
};