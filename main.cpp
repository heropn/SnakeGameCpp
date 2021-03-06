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
		gameManager.GetTextureManager().GetTexture(MyTexture::Type::HelpScreen2),
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
				sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

				if (mainMenu.IsInMainMenu())
				{
					mainMenu.CheckIfButtonWasClicked(mousePosition);
				}
				else if (mainMenu.GetCurrentMode() != MainMenu::Mode::Default)
				{
					if (mainMenu.GetCurrentMode() == MainMenu::Mode::Help)
					{
						mainMenu.GetHelpScreen().CheckIfAnotherPageButtonWasClicked(mousePosition);
					}

					if ((mainMenu.GetHighScoreManagerPtr()->IsReturnButtonClicked(mousePosition) &&
						mainMenu.GetCurrentMode() == MainMenu::Mode::HighScores) ||
						(mainMenu.GetHelpScreen().IsReturnButtonClicked(mousePosition) &&
						(mainMenu.GetCurrentMode() == MainMenu::Mode::Help)) ||
						(mainMenu.GetCreditsScreen().IsReturnButtonClicked(mousePosition) &&
						mainMenu.GetCurrentMode() == MainMenu::Mode::Credits))
					{
						mainMenu.SetIsInMainMenu(true);
						mainMenu.SetCurrentMode(MainMenu::Mode::Default);
					}
				}
				else if (gameManager.IsInSnakeSelectMenu())
				{
					gameManager.CheckIfSnakeWasSelected(mousePosition);
				}
				else if (gameManager.IsInModeSelectMenu())
				{
					gameManager.CheckIfModeWasSelected(mousePosition);
				}
			}
		}

		window.clear(sf::Color(216,253,176));

		if (mainMenu.IsInMainMenu() || mainMenu.GetCurrentMode() != MainMenu::Mode::Default)
		{
			window.clear(sf::Color::Black);
			mainMenu.HighlightHoveredButton(sf::Mouse::getPosition(window));
			mainMenu.Draw();
		}
		// Dop?ki nie ma ko?ca gry, wykonuj...
		else if (!gameManager.IsGameOver())
		{
			// Sprawdza,czy nie zosta? wci?ni?ty jaki? przycisk, je?li jest to W,A,S lub D 
			// to zmie? kierunek snake'a w zale?no?ci od przycisku
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			{
				// Je?li gra jest ustawiona w trybie odwr?conym to zmie? kierunek snake'a 
				// np. z g?ry na d??
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
				gameManager.GetSnakeSelectMenu().HighlightHoveredSnake(sf::Mouse::getPosition(window));
				gameManager.DrawSnakeSelectMenu(&window);
			}
			else if (gameManager.IsInModeSelectMenu())
			{
				gameManager.GetModeSelectMenu().HighlightHoveredMode(sf::Mouse::getPosition(window));
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
				gameManager.UpdateHighScores();
				gameManager.ResetGame();
				mainMenu.SetIsInMainMenu(true);
			}
		}

		window.display();
	}
}