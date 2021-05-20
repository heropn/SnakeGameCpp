#include "..\Headers\TypeInArea.h"
#include <iostream>

TypeInArea::TypeInArea() {}

TypeInArea::TypeInArea(std::shared_ptr<MyFont> fontDisplayText, std::shared_ptr<MyFont> fontTopText)
	: fontDisplayText(fontDisplayText), fontTopText(fontTopText)
{
	SetUpTextes();
	SetUpRectangle();
}

void TypeInArea::UpdateText(sf::String str)
{
	if (playerInput.getSize() < 6)
	{
		playerInput += str;
		displayText.setString(playerInput);
	}
}

void TypeInArea::EreseLastCharacter()
{
	if (playerInput.getSize() > 0)
	{
		playerInput.erase(playerInput.getSize() - 1);
		displayText.setString(playerInput);
	}
}

void TypeInArea::Draw(sf::RenderWindow* window)
{
	window->draw(displayText);
	window->draw(topText);
	window->draw(rectangle);
}

const std::string TypeInArea::GetPlayerName() const
{
	return playerInput;
}

void TypeInArea::GetPlayerInput(char c)
{
	if (c == '\b')
		EreseLastCharacter();
	else
		UpdateText(c);
}

void TypeInArea::SetUpTextes()
{
	displayText.setFont(*fontDisplayText);
	displayText.setCharacterSize(100);
	displayText.setFillColor(sf::Color::Color(25, 255, 142));

	topText.setFont(*fontTopText);
	topText.setCharacterSize(50);
	topText.setFillColor(sf::Color::Color(62,179,39));
	topText.setString("Enter your name:");

	topText.setPosition(300, 300);
	displayText.setPosition(210, 360);
}

void TypeInArea::SetUpRectangle()
{
	rectangle.setSize({ 600, 110 });
	rectangle.setFillColor(sf::Color::Transparent);
	rectangle.setOutlineThickness(5.0f);
	rectangle.setOutlineColor(sf::Color::Color(0, 102, 14));
	rectangle.setPosition(190, 370);
}
