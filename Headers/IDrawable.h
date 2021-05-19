#pragma once
#include <SFML/Graphics.hpp>

// Klasa abstrakcyjna dla klas, które da siê rysowaæ w oknie
class IDrawable
{
public:
	virtual void Draw(sf::RenderWindow* window) = 0;
};