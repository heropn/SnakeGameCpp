#include "..\Headers\Title.h"

Title::Title() {}

void Title::Draw(sf::RenderWindow* window)
{
	window->draw(text);
}

void Title::SetUpText()
{
	text.setFont(*fontPtr);
	text.setString("Snejk");
	text.setCharacterSize(150);
	text.setFillColor(sf::Color::Color(0, 179, 11));
	auto rect = text.getLocalBounds();
	text.setOrigin(rect.width / 2, rect.height / 2);
	text.setPosition(500, 50);
}

void Title::SetFont(std::shared_ptr<MyFont> fontPtr)
{
	this->fontPtr = fontPtr;
	SetUpText();
}