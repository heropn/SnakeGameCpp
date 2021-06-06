#include "..\Headers\ModeSelectMenu.h"


ModeSelectMenu::GameMode::GameMode(std::shared_ptr<MyTexture> texturePtr)
	:texturePtr(texturePtr)
{
	sprite.setTexture(*texturePtr);

	sf::Vector2u size = texturePtr->getSize();

	sprite.setOrigin((float)size.x / 2, (float)size.y / 2);
}

void ModeSelectMenu::GameMode::SetPosition(sf::Vector2f position)
{
	sprite.setPosition(position);
}

const bool ModeSelectMenu::GameMode::IsClicked(sf::Vector2i& position) const
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

void ModeSelectMenu::GameMode::Draw(sf::RenderWindow* window)
{
	window->draw(sprite);
}

ModeSelectMenu::ModeSelectMenu() {}

ModeSelectMenu::ModeSelectMenu(std::shared_ptr<MyFont> fontPtr) : fontPtr(fontPtr)
{
	SetUpText();
}

void ModeSelectMenu::AddTexture(std::shared_ptr<MyTexture> texturePtr)
{
	modes.push_back(texturePtr);
	SetUpGameModes();
}

void ModeSelectMenu::SetUpGameModes()
{
	if (modes.size() < 2)
		return;

	modes[0].SetPosition({ 275, 400 });
	modes[1].SetPosition({ 725, 400 });
}

void ModeSelectMenu::SetUpText()
{
	text.setFont(*fontPtr);
	text.setString("     Choose\nYour GameMode");
	text.setCharacterSize(100);
	text.setFillColor(sf::Color::Color(0, 179, 11));
	auto rect = text.getLocalBounds();
	text.setOrigin(rect.width / 2, 0);
	text.setPosition(500, 50);
}

const MyTexture::Type ModeSelectMenu::GetClickedMode(sf::Vector2i position) const
{
	for (const auto& mode : modes)
	{
		if (mode.IsClicked(position))
		{
			printf("Clicked\n");
			return mode.texturePtr->GetType();
		}
	}

	return MyTexture::Type::None;
}

void ModeSelectMenu::Draw(sf::RenderWindow* window)
{
	for (auto& mode : modes)
	{
		mode.Draw(window);
	}

	window->draw(text);
}