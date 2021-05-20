#pragma once
#include <SFML/Graphics.hpp>
#include "MyTexture.h"
#include "IDrawable.h"

class SnakeSelectMenu : public IDrawable
{
private:
	struct SnakeHead
	{
		sf::Sprite sprite;
		std::shared_ptr<MyTexture> texturePtr;

		SnakeHead(std::shared_ptr<MyTexture> texturePtr);

		void SetPosition(sf::Vector2f position);
	};

	std::vector<SnakeHead> snakes;

public:
	SnakeSelectMenu();

	void AddTexture(std::shared_ptr<MyTexture> texturePtr);

	void SetUpSnakes();

	MyTexture::Type GetClickedSnake(sf::Vector2f position);

	void Draw(sf::RenderWindow* window);
};