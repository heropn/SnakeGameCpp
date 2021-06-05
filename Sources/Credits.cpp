#include "..\headers\Credits.h"

Credits::Credits() {
	PauliTexture.loadFromFile(".\\Textures\\credits.png");
	Pauli.setTexture(PauliTexture);
	Pauli.setPosition(100.0, 300.0);
}

void Credits::Draw(sf::RenderWindow* window) {
	window->draw(Pauli);
	back.Draw(window);
}

bool Credits::CheckIfButtonWasClicked(sf::Vector2i vec)
{
	sf::Vector2f vecF = { (float)vec.x, (float)vec.y };

	return (back.rectangle.getGlobalBounds().contains(vecF.x, vecF.y));

};

void Credits::setFont(std::shared_ptr<MyFont> fontTitleText)
{
	this->fontTitleText = fontTitleText;
	back = Button("RETURN", 600.0, 700.0, fontTitleText);
}