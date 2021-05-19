#include "..\Headers\GameManager.h"
#include <random>
#include <algorithm>

GameManager::GameManager()
{
	snake = Snake(texturesManager.GetTexture(MyTexture::Type::SnakeHeadYellow), texturesManager.GetTexture(MyTexture::Type::SnakeBodyYellow));
	scoreManager.SetFont(fontsManager.GetFont(MyFont::Type::Arial));

	drawableInGameObjects.push_back(&snake);
	drawableInGameObjects.push_back(&background);
	drawableInGameObjects.push_back(&scoreManager);

	loseScreen = LoseScreen(fontsManager.GetFont(MyFont::Type::Arial), fontsManager.GetFont(MyFont::Type::Arial));
	typeInArea = TypeInArea(fontsManager.GetFont(MyFont::Type::Arial), fontsManager.GetFont(MyFont::Type::Arial));

	drawableEndGameObjects.push_back(&loseScreen);
	drawableEndGameObjects.push_back(&typeInArea);

	isGameOver = false;
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

		float x = posX(generator);
		float y = posY(generator);

		pickUp = PickUp(x, y);
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

void GameManager::GenerateSnakePosition()
{
	std::random_device device;
	std::mt19937 generator(device());
	std::uniform_real_distribution<float> posX(150.0f, 850.0f); //x e [100,900] y e [250,750]
	std::uniform_real_distribution<float> posY(300.0f, 700.0f);
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

void GameManager::CheckPickUp()
{
	if (pickUp.IsCollected(&snake))
	{
		scoreManager.AddScore();
		isPickUpCollected = true;
		snake.Grow();
		drawableInGameObjects.erase(std::remove(drawableInGameObjects.begin(), drawableInGameObjects.end(), &pickUp), drawableInGameObjects.end());
		GeneratePickUp();
	}
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
