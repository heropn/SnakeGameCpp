#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class Background
{
private:
	float width;
	float height;
	sf::RectangleShape arena;
public:
	// W momencie tworzenia obiektu zostaj¹ ustawione w³aœciwoœci areny
	Background();

	// Ustawienie w³aœciwoœci areny
	void SetArenasProperties();

	// Funkcja rysuje w oknie gry arenê
	void Draw(sf::RenderWindow* window);

	// Zwraca kszta³t areny
	sf::RectangleShape GetShape();
};
