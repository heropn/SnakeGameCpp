#include "GameManager.h"

void GameManager::DrawPickUp(sf::RenderWindow* window)
{
	pickUp.Draw(window);
}

void GameManager::GeneratePickUp()
{
	std::random_device device;
	std::mt19937 generator(device());
	std::uniform_int_distribution<int>posX(150, 850); //x e [100,900] y e [250,750]
	std::uniform_int_distribution<int>posY(300, 700);

	if (isPickUpCollected)
	{
		isPickUpCollected = false;

		int x = posX(generator);
		int y = posY(generator);

		PickUp pickUp(x, y);
		this->pickUp = pickUp;
	}
}

//podczas tworzenia obiektu wygeneruje pocz¹tkowe po³o¿enie snake'a
GameManager::GameManager()
{
	scores = 0;
	isGameOver = false;
	isPickUpCollected = true;
	GenerateSnakePosition();
	GeneratePickUp();
}

void GameManager::DrawSnake(sf::RenderWindow* window)
{
	snake.Draw(window);
}

// generowanie pocz¹tkowej pozycji snake'a
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
	Snake snake(x, y,Snake::Direction(index));
	this->snake = snake;
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
	if (!snake.IsInArena(&background))//||snake.IsCollision())
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
		IncreaseSnakesSize();
		GeneratePickUp();
	}
}

void GameManager::IncreaseSnakesSize()
{

}