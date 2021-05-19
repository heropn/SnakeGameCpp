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
		
		/*gameManager.CheckWhereIsSnake();

		if (!gameManager.IsGameOver())
		{
			gameManager.CheckPickUp();

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			{
				gameManager.SetDirection(Snake::Direction::Top);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			{
				gameManager.SetDirection(Snake::Direction::Left);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			{
				gameManager.SetDirection(Snake::Direction::Bottom);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			{
				gameManager.SetDirection(Snake::Direction::Right);
			}

			gameManager.DrawBackground(&window);
			gameManager.MoveSnake();
			gameManager.DrawSnake(&window);
			gameManager.DrawPickUp(&window);
		}
		else
		{
			std::cout << "Koniec gry" << std::endl;
		}*/

		window.display();
	}
}