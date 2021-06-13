#pragma once

#include "MyTexture.h"
#include "Button.h"
#include "MyFont.h"

class Help 
{
	sf::Sprite help;
	std::shared_ptr<MyTexture> helpTexture;
	Button back, prev_page, next_page;
	std::shared_ptr<MyFont> fontTitleText;

public:
	Help();
	void Draw(sf::RenderWindow* window, std::string which_page);
	bool CheckIfReturnButtonWasClicked(sf::Vector2i vec);
	bool CheckIfNextPageButtonWasClicked(sf::Vector2i vec);
	bool CheckIfPrevPageButtonWasClicked(sf::Vector2i vec);
	void SetFont(std::shared_ptr<MyFont> font);
	void SetTexture(std::shared_ptr<MyTexture> texture);
};