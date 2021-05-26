#pragma once
#include <SFML/Graphics.hpp>
#include "IDrawable.h"
#include "MyFont.h"

class Button : public IDrawable 
{
private:
	std::shared_ptr<MyFont> fontPtr;
	sf::Text text;
public:
	Button();
	Button(std::string content, float position_x, float position_y, std::shared_ptr<MyFont> fontPtr);
	sf::RectangleShape rectangle;
	void Draw(sf::RenderWindow* window);
};