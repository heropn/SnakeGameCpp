#include "..\Headers\SnakeSelectMenu.h"

SnakeSelectMenu::SnakeHead::SnakeHead(std::shared_ptr<MyTexture> texturePtr)
	:texturePtr(texturePtr)
{
	sprite.setTexture(*texturePtr);
	sprite.setOrigin((float)texturePtr->getSize().x / 2, (float)texturePtr->getSize().x / 2);
}

void SnakeSelectMenu::SnakeHead::SetPosition(sf::Vector2f position)
{
	sprite.setPosition(position);
}

SnakeSelectMenu::SnakeSelectMenu() {}

void SnakeSelectMenu::AddTexture(std::shared_ptr<MyTexture> texturePtr)
{
	snakes.push_back(texturePtr);
}

void SnakeSelectMenu::SetUpSnakes()
{
	if (snakes.size() < 3)
		return;

	snakes[0].SetPosition({ 300, 200 });
	snakes[1].SetPosition({ 700, 200 });
	snakes[2].SetPosition({ 300, 800 });
	snakes[3].SetPosition({ 700, 800 });
}

void SnakeSelectMenu::Draw(sf::RenderWindow* window)
{
	for (const auto& snake : snakes)
	{
		window->draw(snake.sprite);
	}
}