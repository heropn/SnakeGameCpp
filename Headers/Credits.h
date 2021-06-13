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
	Credits(); //konstruktor domyœlny
	void Draw(sf::RenderWindow* window); //rysuje ekran z autorami
	bool CheckIfButtonWasClicked(sf::Vector2i vec); //sprawdza, czy zosta³ klikniêty przycisk powrotu
	void SetFont(std::shared_ptr<MyFont> font); //ustawia czcionkê przycisku
	void SetTexture(std::shared_ptr<MyTexture> texture); //Ustawia teksturê z autorami
};