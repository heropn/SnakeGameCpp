#include <SFML/Graphics.hpp>
#include "Headers/GameManager.h"
#include "Headers/MainMenu.h"

int main()
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(1000, 800), "Snake Game", sf::Style::Close, settings);
	window.setVerticalSyncEnabled(true);
	window.setKeyRepeatEnabled(false);
	window.setFramerateLimit(60);

	GameManager gameManager;
	MainMenu mainMenu(window, 
		gameManager.GetFontsManager().GetFont(MyFont::Type::Snake),
		gameManager.GetFontsManager().GetFont(MyFont::Type::LostIsland),
		gameManager.GetTextureManager().GetTexture(MyTexture::Type::Menu));

	gameManager.GetAudioManager().PlaySound(MySoundBuffer::Type::GameMusic);

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
				if (mainMenu.IsInMainMenu())
					mainMenu.CheckIfButtonWasClicked(sf::Mouse::getPosition(window));
				else if (gameManager.IsInSnakeSelectMenu())
					gameManager.CheckIfSnakeWasSelected(sf::Mouse::getPosition(window));
			}
		}

		window.clear(sf::Color::Color(216,253,176));

		if (mainMenu.IsInMainMenu())
		{
			mainMenu.DrawButtonsAndTitle();
		}
		else if (!gameManager.IsGameOver())
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			{
				if (gameManager.IsReversed())
				{
					gameManager.SetSnakeDirection(Snake::Direction::Bottom);
				}
				else
				{
					gameManager.SetSnakeDirection(Snake::Direction::Top);
				}
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			{
				if (gameManager.IsReversed())
				{
					gameManager.SetSnakeDirection(Snake::Direction::Right);
				}
				else
				{
					gameManager.SetSnakeDirection(Snake::Direction::Left);
				}
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			{
				if (gameManager.IsReversed())
				{
					gameManager.SetSnakeDirection(Snake::Direction::Top);
				}
				else
				{
					gameManager.SetSnakeDirection(Snake::Direction::Bottom);
				}
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			{
				if (gameManager.IsReversed())
				{
					gameManager.SetSnakeDirection(Snake::Direction::Left);
				}
				else
				{
					gameManager.SetSnakeDirection(Snake::Direction::Right);
				}
				
			}

			if (gameManager.IsInSnakeSelectMenu())
			{
				gameManager.DrawSnakeSelectMenu(&window);
			}
			else
			{
				gameManager.CheckIfPickupOrPowerUpIsCollected();
				gameManager.CheckPowerUpDuration();
				gameManager.CheckWhereIsSnake();
				gameManager.MoveSnake();
				gameManager.DrawInGameObjects(&window);
				gameManager.FlickerBorder();
			}
		}
		else
		{
			gameManager.DrawEndGameObjects(&window);

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
			{
				//gameManager.UpdateHighScores();
				gameManager.ResetGame();
				mainMenu.SetIsInMainMenu(true);
			}
		}

		window.display();
	}
}