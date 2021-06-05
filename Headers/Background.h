#pragma once
#include <SFML/Graphics.hpp>
#include "IDrawable.h"
#include "MyTexture.h"

class Background : public IDrawable
{
private:
	float width;
	float height;

	float timeBetweenFlickers;

	sf::RectangleShape border;
	std::shared_ptr<MyTexture> texturePtr;
	sf::Sprite sprite;

	bool isBorderFlickering;

	sf::Clock flickerClock;

public:
	// W momencie tworzenia obiektu zostaj¹ ustawione w³aœciwoœci areny
	Background();

	// Ustawia texture oraz sprite'a
	void SetTextureAndSprite(std::shared_ptr<MyTexture> texturePtr);

	// Funkcja rysuje w oknie gry arenê
	void Draw(sf::RenderWindow* window);

	void Flicker();

	const bool GetFlickerStatus() const;

	void SetFlickerStatus(bool val);

	// Zwraca kszta³t areny
	const sf::RectangleShape& GetShape() const;

private:
	// Ustawienie w³aœciwoœci areny
	void SetArenasProperties();
};
