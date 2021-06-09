#pragma once
#include <SFML/Graphics.hpp>
#include "IDrawable.h"
#include "MyTexture.h"
#include "MyFont.h"

class PowerUpDisplayer : public IDrawable
{
private:
	std::shared_ptr<MyTexture> texturePtr;
	sf::Sprite sprite;

	std::shared_ptr<MyFont> fontPtr;
	sf::Text text;

	sf::Clock clock;

	bool shouldBeDrawn;

public:
	// Konstrutkor domyœlny
	PowerUpDisplayer();

	// Konstruktor parametryczny, ustawia czionkê tekstu
	PowerUpDisplayer(std::shared_ptr<MyFont> fontPtr);

	// Ustawia teksturê, która ma siê wyœwietlaæ
	void SetTextureAndStartDrawing(std::shared_ptr<MyTexture> texturePtr);

	// Przestaje rysowaæ
	void StopDrawing();

	// Rysuje obiekt w oknie
	void Draw(sf::RenderWindow* window);

	// Sprawia, ¿e gdy zostanie ma³o czasu, alfa koloru siê zmienia na ni¿sz¹
	void Flicker();

private:
	// Ustawia wszystkie parametry tekstu
	void SetUpText();
};