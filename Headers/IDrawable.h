#pragma once
#include <SFML/Graphics.hpp>

// Klasa abstrakcyjna dla klas, kt�re da si� rysowa� w oknie
class IDrawable
{
public:
	virtual void Draw(sf::RenderWindow* window) = 0;
};
