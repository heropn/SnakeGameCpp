#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class Background
{
private:
	int width;
	int height;
	sf::RectangleShape arena;
public:
	Background();
	void SetArenasProperties();
	void Draw(sf::RenderWindow* window);
	sf::RectangleShape GetShape();

};