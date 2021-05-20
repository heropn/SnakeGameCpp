#pragma once
#include <SFML/Graphics.hpp>
#include "MyTexture.h"
#include "IDrawable.h"
#include "MyFont.h"

class SnakeSelectMenu : public IDrawable
{
private:
	struct SnakeHead : public IDrawable
	{
		sf::Sprite sprite;
		std::shared_ptr<MyTexture> texturePtr;

		SnakeHead(std::shared_ptr<MyTexture> texturePtr);

		void SetPosition(sf::Vector2f position);

		const bool IsClicked(sf::Vector2i& position) const;

		void Draw(sf::RenderWindow* window);
	};

	std::vector<SnakeHead> snakes;
	sf::Text text;
	std::shared_ptr<MyFont> fontPtr;

public:
	SnakeSelectMenu();

	SnakeSelectMenu(std::shared_ptr<MyFont> fontPtr);

	void AddTexture(std::shared_ptr<MyTexture> texturePtr);

	const MyTexture::Type GetClickedSnake(sf::Vector2i position) const;

	void Draw(sf::RenderWindow* window);

private:
	void SetUpSnakes();

	void SetUpText();
};