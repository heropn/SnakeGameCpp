#include "..\Headers\PowerUpDisplayer.h"\

PowerUpDisplayer::PowerUpDisplayer() : shouldBeDrawn(false) {}

PowerUpDisplayer::PowerUpDisplayer(std::shared_ptr<MyFont> fontPtr) :
	shouldBeDrawn(false), fontPtr(fontPtr)
{
	sprite.setPosition(100, 180);
	SetUpText();
}

void PowerUpDisplayer::SetTextureAndStartDrawing(std::shared_ptr<MyTexture> texturePtr)
{
	sprite.setColor({ 255, 255, 255 });
	sprite.setTexture(*texturePtr);
	sprite.setScale({ 1.5f, 1.5f });
	shouldBeDrawn = true;
	clock.restart();
}

void PowerUpDisplayer::Flicker()
{
	if (shouldBeDrawn && clock.getElapsedTime().asSeconds() > 4.0f)
	{
		sprite.setColor({ 255, 255, 255, 100 });
	}
}

void PowerUpDisplayer::StopDrawing()
{
	shouldBeDrawn = false;
}

void PowerUpDisplayer::Draw(sf::RenderWindow* window)
{
	window->draw(text);

	if (shouldBeDrawn)
	{
		window->draw(sprite);
	}
}

void PowerUpDisplayer::SetUpText()
{
	text.setFont(*fontPtr);
	text.setString("Active Powerup:");
	text.setCharacterSize(20);
	text.setLineSpacing(1.0f);
	text.setFillColor(sf::Color::Color(39, 102, 42));
	auto rect = text.getLocalBounds();
	text.setOrigin(rect.width / 2, rect.height / 2);
	text.setPosition(120, 160);
}
