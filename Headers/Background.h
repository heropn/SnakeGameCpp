#pragma once
#include <SFML/Graphics.hpp>
#include "IDrawable.h"
#include "MyTexture.h"

class Background : public IDrawable
{
private:
	float width;
	float height;
	sf::RectangleShape border;
	std::shared_ptr<MyTexture> texturePtr;
	sf::Sprite sprite;

public:
	// W momencie tworzenia obiektu zostaj¹ ustawione w³aœciwoœci areny
	Background();

	void SetTextureAndSprite(std::shared_ptr<MyTexture> texturePtr);

	// Funkcja rysuje w oknie gry arenê
	void Draw(sf::RenderWindow* window);

	// Zwraca kszta³t areny
	const sf::RectangleShape& GetShape() const;

private:
	// Ustawienie w³aœciwoœci areny
	void SetArenasProperties();
};
