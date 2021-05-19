#include <SFML/Graphics.hpp>
#include "Headers/GameManager.h"
#include <iostream>

int main()
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(1000, 800), "Snake Game", sf::Style::Close, settings);
	window.setVerticalSyncEnabled(true);
	window.setKeyRepeatEnabled(false);

	GameManager gameManager;

	while (window.isOpen())
	{
		sf::Event windowEvent;
		while (window.pollEvent(windowEvent))
		{
			if (windowEvent.type == sf::Event::Closed)
				window.close();
		}
		window.clear();
		
		gameManager.CheckWhereIsSnake();

		if (!gameManager.IsGameOver())
		{
			gameManager.CheckPickUp();

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			{
				gameManager.SetSnakeDirection(Snake::Direction::Top);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			{
				gameManager.SetSnakeDirection(Snake::Direction::Left);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			{
				gameManager.SetSnakeDirection(Snake::Direction::Bottom);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			{
				gameManager.SetSnakeDirection(Snake::Direction::Right);
			}

			gameManager.MoveSnake();
			gameManager.DrawInGameObjects(&window);
		}
		else
		{
			std::cout << "Koniec gry" << std::endl;
		}

		window.display();
	}
}