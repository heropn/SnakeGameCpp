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
	Help(); //konstruktor domyœlny
	void Draw(sf::RenderWindow* window, const std::string& which_page); //rysuje ekran pomocy
	bool CheckIfReturnButtonWasClicked(sf::Vector2i vec); //sprawdza, czy zosta³ klikniêty przycisk powrotu do menu 
	bool CheckIfNextPageButtonWasClicked(sf::Vector2i vec); //sprawdza, czy zosta³ klikniêty przycisk nastêpnej strony
	bool CheckIfPrevPageButtonWasClicked(sf::Vector2i vec); //sprawdza, czy zosta³ klikniêty przycisk pierwszej strony
	void SetFont(std::shared_ptr<MyFont> font); //ustawia czcionkê
	void SetTexture(std::shared_ptr<MyTexture> texture); //ustawia teksturê z ekranem pomocy
};