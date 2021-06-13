#include "..\Headers\Help.h"

Help::Help() : screenType(ScreenType::First) {}

void Help::SetTextures(std::shared_ptr<MyTexture> textureFirst, std::shared_ptr<MyTexture> textureSecond)
{
	helpFirstPageTexture = textureFirst;
	helpSecondPageTexture = textureSecond;
	help.setTexture(*helpFirstPageTexture);
	help.setScale({ 0.9f, 0.9f });
	help.setPosition({ 50.0f, -20.0f });
}

void Help::HiglightHoveredButton(sf::Vector2i vec)
{
	sf::Vector2f vecF = { (float)vec.x, (float)vec.y };

	if (backButton.GetShape().getGlobalBounds().contains(vecF.x, vecF.y))
	{
		backButton.SetHighlightColor();
	}
	else if (anotherPageButton.GetShape().getGlobalBounds().contains(vecF.x, vecF.y))
	{
		anotherPageButton.SetHighlightColor();
	}
	else
	{
		backButton.SetDefaultColor();
		anotherPageButton.SetDefaultColor();
	}
}

void Help::Draw(sf::RenderWindow* window)
{
	window->draw(help);
	backButton.Draw(window);
	anotherPageButton.Draw(window);
}

bool Help::IsReturnButtonClicked(sf::Vector2i vec)
{
	sf::Vector2f vecF = { (float)vec.x, (float)vec.y };

	return backButton.GetShape().getGlobalBounds().contains(vecF.x, vecF.y);
}

void Help::CheckIfAnotherPageButtonWasClicked(sf::Vector2i vec)
{
	sf::Vector2f vecF = { (float)vec.x, (float)vec.y };

	if (anotherPageButton.GetShape().getGlobalBounds().contains(vecF.x, vecF.y))
	{
		if (screenType == ScreenType::First)
		{
			anotherPageButton.SetTextString("FIRST PAGE");
			screenType = ScreenType::Second;
			help.setTexture(*helpSecondPageTexture);
		}
		else
		{
			anotherPageButton.SetTextString("SECOND PAGE");
			screenType = ScreenType::First;
			help.setTexture(*helpFirstPageTexture);
		}
	}
}

void Help::SetFont(std::shared_ptr<MyFont> font)
{
	this->fontTitleText = font;
	backButton = Button("RETURN", 50.0f, 700.0f, font);
	anotherPageButton = Button("SECOND PAGE", 600.0f, 700.0f, font);
}