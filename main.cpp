#include <SFML/Graphics.hpp>
#include "Headers/GameManager.h"
#include <iostream>
#include "Headers/SnakeSelectMenu.h"

int main()
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(1000, 800), "Snake Game", sf::Style::Close, settings);
	window.setVerticalSyncEnabled(true);
	window.setKeyRepeatEnabled(false);
	window.setFramerateLimit(60);

	GameManager gameManager;
	
	SnakeSelectMenu sSM(gameManager.GetFontsManager().GetFont(MyFont::Type::Snake));
	sSM.AddTexture(gameManager.GetTextureManager().GetTexture(MyTexture::Type::SnakeBigGreen));
	sSM.AddTexture(gameManager.GetTextureManager().GetTexture(MyTexture::Type::SnakeBigPink));
	sSM.AddTexture(gameManager.GetTextureManager().GetTexture(MyTexture::Type::SnakeBigYellow));
	sSM.AddTexture(gameManager.GetTextureManager().GetTexture(MyTexture::Type::SnakeBigBlue));

	while (window.isOpen())
	{
		sf::Event windowEvent;
		while (window.pollEvent(windowEvent))
		{
			if (windowEvent.type == sf::Event::Closed)
			{
				window.close();
			}
			else if (gameManager.IsGameOver() && windowEvent.type == sf::Event::TextEntered)
			{
				gameManager.GetTypeInAreaManager().GetPlayerInput(windowEvent.text.unicode);
			}
			else if (windowEvent.type == sf::Event::MouseButtonReleased)
			{
				sSM.GetClickedSnake(sf::Mouse::getPosition(window));
			}
		}

		window.clear(sf::Color::Color(196,235,190));

		//sSM.Draw(&window);

		if (!gameManager.IsGameOver())
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			{
				gameManager.SetSnakeDirection(Snake::Direction::Top);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			{
				gameManager.SetSnakeDirection(Snake::Direction::Left);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			{
				gameManager.SetSnakeDirection(Snake::Direction::Bottom);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			{
				gameManager.SetSnakeDirection(Snake::Direction::Right);
			}

			gameManager.CheckPickUp();
			gameManager.CheckWhereIsSnake();
			gameManager.MoveSnake();
			gameManager.DrawInGameObjects(&window);
		}
		else
		{
			gameManager.DrawEndGameObjects(&window);

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
			{
				gameManager.UpdateHighScores();
				break;
			}
		}

		window.display();
	}
}