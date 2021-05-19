#include "..\Headers\GameManager.h"
#include <random>

GameManager::GameManager()
{
	snake = Snake(texturesManager.GetTexture(MyTexture::Type::SnakeHead), texturesManager.GetTexture(MyTexture::Type::SnakeBody));

	scores = 0;
	isGameOver = false;
	isPickUpCollected = true;
	GenerateSnakePosition();
	GeneratePickUp();
}

void GameManager::DrawPickUp(sf::RenderWindow* window)
{
	pickUp.Draw(window);
}

void GameManager::GeneratePickUp()
{
	std::random_device device;
	std::mt19937 generator(device());
	std::uniform_real_distribution<float> posX(150, 850); //x e [100,900] y e [250,750]
	std::uniform_real_distribution<float> posY(300, 700);

	if (isPickUpCollected)
	{
		isPickUpCollected = false;

		float x = posX(generator);
		float y = posY(generator);

		pickUp = PickUp(x, y);
	}
}

void GameManager::DrawSnake(sf::RenderWindow* window)
{
	snake.Draw(window);
}

void GameManager::GenerateSnakePosition()
{
	std::random_device device;
	std::mt19937 generator(device());
	std::uniform_int_distribution<int>posX(150, 850); //x e [100,900] y e [250,750]
	std::uniform_int_distribution<int>posY(300, 700);
	std::uniform_int_distribution<int>direction(0,3); // kierunek

	int x = posX(generator);
	int y = posY(generator);
	int index = direction(generator);

	snake.SetDirection(Snake::Direction(index));
	snake.SetPosition((float)x, (float)y);
}

void GameManager::MoveSnake()
{
	snake.Move();
}
void GameManager::SetDirection(Snake::Direction direction)
{
	snake.SetDirection(direction);
}

void GameManager::DrawBackground(sf::RenderWindow* window)
{
	background.Draw(window);
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
		scores++;
		isPickUpCollected = true;
		snake.Grow();
		GeneratePickUp();
	}
}
