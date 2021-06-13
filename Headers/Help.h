#pragma once

#include "MyTexture.h"
#include "Button.h"
#include "MyFont.h"

class Help 
{
private:

	enum class ScreenType
	{
		First,
		Second
	};

	sf::Sprite help;
	std::shared_ptr<MyTexture> helpFirstPageTexture;
	std::shared_ptr<MyTexture> helpSecondPageTexture;
	Button backButton;
	Button anotherPageButton;
	std::shared_ptr<MyFont> fontTitleText;
	ScreenType screenType;

public:
	Help(); //konstruktor domyœlny
	void Draw(sf::RenderWindow* window); //rysuje ekran pomocy
	bool IsReturnButtonClicked(sf::Vector2i vec); //sprawdza, czy zosta³ klikniêty przycisk powrotu do menu 
	void CheckIfAnotherPageButtonWasClicked(sf::Vector2i vec); //sprawdza, czy zosta³ klikniêty przycisk nastêpnej strony
	void SetFont(std::shared_ptr<MyFont> font); //ustawia czcionkê
	void SetTextures(std::shared_ptr<MyTexture> textureFirst, std::shared_ptr<MyTexture> textureSecond); //ustawia teksturê z ekranem pomocy
	void HiglightHoveredButton(sf::Vector2i vec); // Podœwietla przycisk jeœli jest nad nim myszka
};