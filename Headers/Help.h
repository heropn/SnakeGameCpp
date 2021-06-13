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
	// Konstruktor domyœlny
	Help();

	// Rysuje ekran pomocy
	void Draw(sf::RenderWindow* window);

	// Sprawdza, czy zosta³ klikniêty przycisk powrotu do menu 
	bool IsReturnButtonClicked(sf::Vector2i vec);

	// Sprawdza, czy zosta³ klikniêty przycisk nastêpnej strony
	void CheckIfAnotherPageButtonWasClicked(sf::Vector2i vec);

	// Ustawia czcionkê
	void SetFont(std::shared_ptr<MyFont> font);

	// Ustawia teksturê z ekranem pomocy
	void SetTextures(std::shared_ptr<MyTexture> textureFirst, std::shared_ptr<MyTexture> textureSecond);

	// Podœwietla przycisk jeœli jest nad nim myszka
	void HiglightHoveredButton(sf::Vector2i vec);
};