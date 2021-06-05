#pragma once
#include "IDrawable.h"
#include "MyTexture.h"
#include "Button.h"
#include "MyFont.h"

class Credits : public IDrawable 
{
	sf::Sprite sprite;
	std::shared_ptr<MyTexture> texture;
	Button back;
	std::shared_ptr<MyFont> fontTitleText;

public:
	Credits();
	void Draw(sf::RenderWindow* window);
	bool CheckIfButtonWasClicked(sf::Vector2i vec);
	void SetFont(std::shared_ptr<MyFont> font);
	void SetTexture(std::shared_ptr<MyTexture> texture);
};