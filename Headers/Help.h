#pragma once
#include "IDrawable.h"
#include "MyTexture.h"
#include "Button.h"
#include "MyFont.h"

class Help : public IDrawable
{
	sf::Sprite help;
	std::shared_ptr<MyTexture> helpTexture;
	Button back;
	std::shared_ptr<MyFont> fontTitleText;

public:
	Help();
	void Draw(sf::RenderWindow* window);
	bool CheckIfButtonWasClicked(sf::Vector2i vec);
	void SetFont(std::shared_ptr<MyFont> font);
	void SetTexture(std::shared_ptr<MyTexture> texture);
};