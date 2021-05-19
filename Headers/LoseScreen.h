#pragma once
#include <SFML/Graphics.hpp>
#include "MyFont.h"
#include "TypeInArea.h"
#include "IDrawable.h"

class LoseScreen : public IDrawable
{
private:
	sf::Text titleText;
	std::shared_ptr<MyFont> fontTitle;
	sf::Text scoreText;
	std::shared_ptr<MyFont> fontScore;

public:
	LoseScreen();

	LoseScreen(std::shared_ptr<MyFont> fontTitle, std::shared_ptr<MyFont> fontScore);

	void Draw(sf::RenderWindow* window);

	void SetScore(int score);

private:
	void SetUpTextes();
};