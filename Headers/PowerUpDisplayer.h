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
	PowerUpDisplayer();

	PowerUpDisplayer(std::shared_ptr<MyFont> fontPtr);

	void SetTextureAndStartDrawing(std::shared_ptr<MyTexture> texturePtr);

	void StopDrawing();

	void Draw(sf::RenderWindow* window);

	void Flicker();

private:
	void SetUpText();
};