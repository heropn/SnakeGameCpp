#include "..\headers\Help.h"

Help::Help() {
	helpTexture.loadFromFile(".\\Textures\\HelpScreen.png");
	help.setTexture(helpTexture);
	help.setPosition(0.0, -30.0);
}

void Help::Draw(sf::RenderWindow* window) {
	window->draw(help);
	back.Draw(window);
}

bool Help::CheckIfButtonWasClicked(sf::Vector2i vec)
{
	sf::Vector2f vecF = { (float)vec.x, (float)vec.y };

	return (back.rectangle.getGlobalBounds().contains(vecF.x, vecF.y));

};

void Help::setFont(std::shared_ptr<MyFont> fontTitleText)
{
	this->fontTitleText = fontTitleText;
	back = Button("RETURN", 645, 730.0, fontTitleText);
}