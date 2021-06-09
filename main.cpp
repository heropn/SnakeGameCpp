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
		gameManager.GetTextureManager().GetTexture(MyTexture::Type::Menu),
		gameManager.GetTextureManager().GetTexture(MyTexture::Type::CreditsScreen),
		gameManager.GetTextureManager().GetTexture(MyTexture::Type::HelpScreen),
		&gameManager.GetHighScoreManager());

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
				else if (mainMenu.currentMode != MainMenu::Mode::Default) {
					if (mainMenu.highScoreManagerPtr->CheckIfButtonWasClicked(sf::Mouse::getPosition(window)) ||
						mainMenu.helpScreen.CheckIfButtonWasClicked(sf::Mouse::getPosition(window)) ||
						mainMenu.creditsScreen.CheckIfButtonWasClicked(sf::Mouse::getPosition(window))) {
						mainMenu.SetIsInMainMenu(true);
						mainMenu.currentMode = MainMenu::Mode::Default;
					}
				}
				else if (gameManager.IsInSnakeSelectMenu())
					gameManager.CheckIfSnakeWasSelected(sf::Mouse::getPosition(window));
				else if (gameManager.IsInModeSelectMenu())
					gameManager.CheckIfModeWasSelected(sf::Mouse::getPosition(window));
			}
		}

		window.clear(sf::Color(216,253,176));

		if (mainMenu.IsInMainMenu() || mainMenu.currentMode != MainMenu::Mode::Default)
		{
			window.clear(sf::Color::Black);
			mainMenu.DrawButtonsAndTitle();
		}
		// Dopóki nie ma koñca gry, wykonuj...
		else if (!gameManager.IsGameOver())
		{
			// Sprawdza,czy nie zosta³ wciœniêty jakiœ przycisk, jeœli jest to W,A,S lub D 
			// to zmieñ kierunek snake'a w zale¿noœci od przycisku
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			{
				// Jeœli gra jest ustawiona w trybie odwróconym to zmieñ kierunek snake'a 
				// np. z góry na dó³
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
			else if (gameManager.IsInModeSelectMenu())
			{
				gameManager.DrawModeSelectMenu(&window);
			}
			else
			{
				gameManager.CheckIfPickupOrPowerUpIsCollected();
				gameManager.CheckPowerUpDuration();
				gameManager.CheckWhereIsSnake();
				gameManager.MoveSnake();
				gameManager.DrawInGameObjects(&window);
				gameManager.FlickerObjects();
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