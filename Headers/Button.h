#pragma once
#include <SFML/Graphics.hpp>
#include "IDrawable.h"
#include "MyFont.h"

class Button : public IDrawable 
{
private:
	std::shared_ptr<MyFont> fontPtr;
	sf::Text text;
	sf::RectangleShape rectangle;
public:
	// Konstruktor domyœlny
	Button();

	// Konstruktor parametryczny, ustawia tekst w œrodku buttona, jego pozycje oraz czcionkê
	Button(std::string content, float position_x, float position_y, std::shared_ptr<MyFont> fontPtr);

	// Rysuje przycisk
	void Draw(sf::RenderWindow* window);

	// Ustawia kolor podczas podœwietlenia
	void SetHighlightColor();
	
	// Ustawia normalny kolor
	void SetDefaultColor();

	// Ustawia string w Button'ie
	void SetTextString(const sf::String& str);

	// Zwraca RectangeShape Button'a
	const sf::RectangleShape& GetShape() const;
};