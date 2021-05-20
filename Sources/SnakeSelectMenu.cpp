#include "..\Headers\SnakeSelectMenu.h"

SnakeSelectMenu::SnakeHead::SnakeHead(std::shared_ptr<MyTexture> texturePtr)
	:texturePtr(texturePtr)
{
	sprite.setTexture(*texturePtr);

	sf::Vector2u size = texturePtr->getSize();

	sprite.setOrigin((float)size.x / 2, (float)size.y / 2);
}

void SnakeSelectMenu::SnakeHead::SetPosition(sf::Vector2f position)
{
	sprite.setPosition(position);
}

const bool SnakeSelectMenu::SnakeHead::IsClicked(sf::Vector2i& position) const
{
	sf::Vector2f spritePosition = sprite.getPosition();
	sf::Vector2u size = texturePtr->getSize();

	if (position.y > spritePosition.y - ((float)size.y / 2) &&
		position.y < spritePosition.y + ((float)size.y / 2) &&
		position.x > spritePosition.x - ((float)size.x / 2) &&
		position.x < spritePosition.x + ((float)size.x / 2))
	{
		return true;
	}

	return false;
}

void SnakeSelectMenu::SnakeHead::Draw(sf::RenderWindow* window)
{
	window->draw(sprite);
}

SnakeSelectMenu::SnakeSelectMenu() {}

SnakeSelectMenu::SnakeSelectMenu(std::shared_ptr<MyFont> fontPtr) : fontPtr(fontPtr)
{
	SetUpText();
}

void SnakeSelectMenu::AddTexture(std::shared_ptr<MyTexture> texturePtr)
{
	snakes.push_back(texturePtr);
	SetUpSnakes();
}

void SnakeSelectMenu::SetUpSnakes()
{
	if (snakes.size() < 4)
		return;

	snakes[0].SetPosition({ 200, 450 });
	snakes[1].SetPosition({ 400, 450 });
	snakes[2].SetPosition({ 600, 450 });
	snakes[3].SetPosition({ 800, 450 });
}

void SnakeSelectMenu::SetUpText()
{
	text.setFont(*fontPtr);
	text.setString("   Choose\nYour Snejk");
	text.setCharacterSize(100);
	text.setFillColor(sf::Color::Color(0, 179, 11));
	auto rect = text.getLocalBounds();
	text.setOrigin(rect.width / 2, 0);
	text.setPosition(500, 50);
}

const MyTexture::Type SnakeSelectMenu::GetClickedSnake(sf::Vector2i position) const
{
	for (const auto& snake : snakes)
	{
		if (snake.IsClicked(position))
		{
			printf("Clicked\n");
			return snake.texturePtr->GetType();
		}
	}

	return MyTexture::Type::None;
}

void SnakeSelectMenu::Draw(sf::RenderWindow* window)
{
	for (auto& snake : snakes)
	{
		snake.Draw(window);
	}

	window->draw(text);
}