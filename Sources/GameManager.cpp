#include "..\Headers\GameManager.h"
#include <random>
#include <algorithm>

GameManager::GameManager()
{
	loseScreen = LoseScreen(fontsManager.GetFont(MyFont::Type::LostIsland),
		fontsManager.GetFont(MyFont::Type::LostIsland));
	typeInArea = TypeInArea(fontsManager.GetFont(MyFont::Type::LostIsland),
		fontsManager.GetFont(MyFont::Type::LostIsland));

	scoreManager.SetFont(fontsManager.GetFont(MyFont::Type::Snake));
	title.SetFont(fontsManager.GetFont(MyFont::Type::Snake));
	background.SetTextureAndSprite(texturesManager.GetTexture(MyTexture::Type::Arena));
	highScoreManager.SetFonts(fontsManager.GetFont(MyFont::Type::Arial),
		fontsManager.GetFont(MyFont::Type::Arial));

	snakeSelectMenu = SnakeSelectMenu(GetFontsManager().GetFont(MyFont::Type::Snake));
	snakeSelectMenu.AddTexture(GetTextureManager().GetTexture(MyTexture::Type::SnakeBigGreen));
	snakeSelectMenu.AddTexture(GetTextureManager().GetTexture(MyTexture::Type::SnakeBigPink));
	snakeSelectMenu.AddTexture(GetTextureManager().GetTexture(MyTexture::Type::SnakeBigYellow));
	snakeSelectMenu.AddTexture(GetTextureManager().GetTexture(MyTexture::Type::SnakeBigBlue));

	drawableInGameObjects.push_back(&background);
	drawableInGameObjects.push_back(&snake);
	drawableInGameObjects.push_back(&scoreManager);
	drawableInGameObjects.push_back(&title);

	drawableEndGameObjects.push_back(&loseScreen);
	drawableEndGameObjects.push_back(&typeInArea);

	isGameOver = false;
	isInSnakeSelect = true;
	isPickUpCollected = true;
	GenerateSnakePosition();
	GeneratePickUp();
}

void GameManager::GeneratePickUp()
{
	std::random_device device;
	std::mt19937 generator(device());
	std::uniform_real_distribution<float> posX(150.0f, 850.0f); //x e [100,900] y e [250,750]
	std::uniform_real_distribution<float> posY(300.0f, 700.0f);

	if (isPickUpCollected)
	{
		isPickUpCollected = false;
		bool isAvailable = false;
		float x = posX(generator);
		float y = posY(generator);

		if (pickUp.GetTexture())
		{
			while (!isAvailable)
			{
				x = posX(generator);
				y = posY(generator);

				if (!snake.IsPickUpOnSnake(x, y, pickUp.GetSize()))
				{
					isAvailable = true;
				}
			}
		}

		pickUp = PickUp(x, y, texturesManager.GetTexture(MyTexture::Type::Apple));
		drawableInGameObjects.push_back(&pickUp);
	}
}

void GameManager::DrawInGameObjects(sf::RenderWindow* window)
{
	for (const auto obj : drawableInGameObjects)
	{
		obj->Draw(window);
	}
}

void GameManager::DrawEndGameObjects(sf::RenderWindow* window)
{
	for (const auto obj : drawableEndGameObjects)
	{
		obj->Draw(window);
	}
}

void GameManager::DrawSnakeSelectMenu(sf::RenderWindow* window)
{
	snakeSelectMenu.Draw(window);
}

void GameManager::GenerateSnakePosition()
{
	std::random_device device;
	std::mt19937 generator(device());
	std::uniform_real_distribution<float> posX(300.0f, 700.0f); //x e [300, 700] y e [400,600]
	std::uniform_real_distribution<float> posY(400.0f, 600.0f);
	std::uniform_int_distribution<int>direction(0,3); // kierunek

	float x = posX(generator);
	float y = posY(generator);
	int index = direction(generator);

	snake.SetDirection(Snake::Direction(index));
	snake.SetPosition(x, y);
}

void GameManager::MoveSnake()
{
	snake.Move();
}

void GameManager::SetSnakeDirection(Snake::Direction direction)
{
	snake.SetDirection(direction);
}

void GameManager::CheckWhereIsSnake()
{
	if (!snake.IsInArena(&background) || snake.IsCollision())
	{
		loseScreen.SetScore(scoreManager.GetScore());
		audioManager.PlaySound(MySoundBuffer::Type::Defeat);
		sf::sleep(sf::seconds(1.0f));
		isGameOver = true;
	}
}

bool GameManager::IsGameOver()
{
	if (isGameOver)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool GameManager::IsInSnakeSelectMenu()
{
	return isInSnakeSelect;
}

void GameManager::CheckIfPickupIsCollected()
{
	if (pickUp.IsCollected(&snake))
	{
		audioManager.PlaySound(MySoundBuffer::Type::Coin);
		scoreManager.AddScore();
		isPickUpCollected = true;
		snake.Grow();
		drawableInGameObjects.erase(std::remove(drawableInGameObjects.begin(), drawableInGameObjects.end(), &pickUp), drawableInGameObjects.end());
		GeneratePickUp();
	}
}

void GameManager::CheckIfSnakeWasSelected(sf::Vector2i position)
{
	switch (snakeSelectMenu.GetClickedSnake(position))
	{
		case MyTexture::Type::SnakeBigGreen:
		{
			snake.SetTextures(texturesManager.GetTexture(MyTexture::Type::SnakeHeadGreen),
				texturesManager.GetTexture(MyTexture::Type::SnakeBodyGreen));
		}
		break;
		case MyTexture::Type::SnakeBigBlue:
		{
			snake.SetTextures(texturesManager.GetTexture(MyTexture::Type::SnakeHeadBlue),
				texturesManager.GetTexture(MyTexture::Type::SnakeBodyBlue));
		}
		break;
		case MyTexture::Type::SnakeBigYellow:
		{
			snake.SetTextures(texturesManager.GetTexture(MyTexture::Type::SnakeHeadYellow),
				texturesManager.GetTexture(MyTexture::Type::SnakeBodyYellow));
		}
		break;
		case MyTexture::Type::SnakeBigPink:
		{
			snake.SetTextures(texturesManager.GetTexture(MyTexture::Type::SnakeHeadPink),
				texturesManager.GetTexture(MyTexture::Type::SnakeBodyPink));
		}
		break;
		default:
			return;
			break;
	}

	isInSnakeSelect = false;
}

void GameManager::ResetGame()
{
	scoreManager.ResetScore();
	typeInArea.Reset();

	drawableInGameObjects.erase(std::remove(drawableInGameObjects.begin(), drawableInGameObjects.end(), &pickUp), drawableInGameObjects.end());

	snake.Reset();

	isPickUpCollected = true;
	GenerateSnakePosition();
	GeneratePickUp();

	isGameOver = false;
	isInSnakeSelect = true;
}

void GameManager::UpdateHighScores()
{
	highScoreManager.AddHighScore(scoreManager.GetScore(), typeInArea.GetPlayerName());
}

const TexturesManager& GameManager::GetTextureManager() const
{
	return texturesManager;
}

const FontsManager& GameManager::GetFontsManager() const
{
	return fontsManager;
}

const ScoreManager& GameManager::GetScoreManager() const
{
	return scoreManager;
}

TypeInArea& GameManager::GetTypeInAreaManager()
{
	return typeInArea;
}

const HighScoreManager& GameManager::GetHighScoreManager() const
{
	return highScoreManager;
}

const AudioManager& GameManager::GetAudioManager() const
{
	return audioManager;
}
