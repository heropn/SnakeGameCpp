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
	Button(); //konstruktor domyœlny
	Button(std::string content, float position_x, float position_y, std::shared_ptr<MyFont> fontPtr); //konstruktor parametryczny
	void Draw(sf::RenderWindow* window); //rysuje przycisk
	void SetHighlightColor();
	void SetDefaultColor();
	void SetTextString(const sf::String& str);
	const sf::RectangleShape& GetShape() const;
};