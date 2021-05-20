#pragma once
#include "IDrawable.h"
#include "MyFont.h"

class Title : public IDrawable
{
private:
	sf::Text text;
	std::shared_ptr<MyFont> fontPtr;
public:
	Title();
	void Draw(sf::RenderWindow* window);
	void SetFont(std::shared_ptr<MyFont> fontPtr);
private:
	void SetUpText();
};