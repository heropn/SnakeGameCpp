#include "..\Headers\GameManager.h"
#include <random>
#include <algorithm>

GameManager::GameManager() : isGameOver(false), isInSnakeSelect(true), isInModeSelect(true),
	isPickUpCollected(true), isPowerUpCollected(true), isReversed(false), isPlayingClassicMode(true),
	timeBetweenPowerUps(-1.0f), powerUpDuration(5.0f), snakeSpeedMultiplier(1.5f),
	howManyBlocks(10)
{
	loseScreen = LoseScreen(fontsManager.GetFont(MyFont::Type::LostIsland),
		fontsManager.GetFont(MyFont::Type::LostIsland));
	typeInArea = TypeInArea(fontsManager.GetFont(MyFont::Type::LostIsland),
		fontsManager.GetFont(MyFont::Type::LostIsland));
	powerUpDisplayer = PowerUpDisplayer(fontsManager.GetFont(MyFont::Type::LostIsland));

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

	modeSelectMenu = ModeSelectMenu(GetFontsManager().GetFont(MyFont::Type::Snake),
		GetFontsManager().GetFont(MyFont::Type::LostIsland));
	modeSelectMenu.AddTexture(GetTextureManager().GetTexture(MyTexture::Type::ClassicArena));
	modeSelectMenu.AddTexture(GetTextureManager().GetTexture(MyTexture::Type::UltraArena));

	drawableInGameObjects.push_back(&background);
	drawableInGameObjects.push_back(&snake);
	drawableInGameObjects.push_back(&scoreManager);
	drawableInGameObjects.push_back(&title);

	drawableEndGameObjects.push_back(&loseScreen);
	drawableEndGameObjects.push_back(&typeInArea);

	GenerateSnakePosition();
	GeneratePickUp();
	GeneratePowerUp();

	audioManager.PlaySound(MySoundBuffer::Type::MenuMusic);
}

bool GameManager::IsObjectOnBlock(float posX, float posY, sf::Vector2u objSize, float additionalValue)
{
	for (const auto& block : blocks)
	{
		if (block->IsColliding({ posX, posY }, objSize, additionalValue))
		{
			return true;
		}
	}
	
	return false;
}

void GameManager::GeneratePickUp()
{
	if (isPickUpCollected)
	{
		std::random_device device;
		std::mt19937 generator(device());
		std::uniform_real_distribution<float> posX(150.0f, 850.0f); //x e [100,900] y e [250,750]
		std::uniform_real_distribution<float> posY(300.0f, 700.0f);

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

				if (!snake.IsObjectOnSnake(x, y, pickUp.GetSize()) &&
					!IsObjectOnBlock(x, y, pickUp.GetSize()))
				{
					isAvailable = true;
				}
			}
		}

		pickUp = PickUp(x, y, texturesManager.GetTexture(MyTexture::Type::Apple));
		drawableInGameObjects.push_back(&pickUp);
	}
}

void GameManager::GeneratePowerUp()
{
	if (isPlayingClassicMode)
		return;

	if (clock.getElapsedTime().asSeconds() > timeBetweenPowerUps
		|| timeBetweenPowerUps < 0)
	{
		if (!isPowerUpCollected)
		{
			clock.restart();
			drawableInGameObjects.erase(std::remove(drawableInGameObjects.begin(),
				drawableInGameObjects.end(), &powerUp), drawableInGameObjects.end());

			durationTime.restart();
		}

		std::random_device device;
		std::mt19937 generator(device());
		std::uniform_real_distribution<float> posX(150.0f, 850.0f); //x e [100,900] y e [250,750]
		std::uniform_real_distribution<float> posY(300.0f, 700.0f);

		timeBetweenPowerUps = 10.0f;
		isPowerUpCollected = false;
		bool isAvailable = false;
		float x = posX(generator);
		float y = posY(generator);

		if (powerUp.GetTexture())
		{
			while (!isAvailable)
			{
				x = posX(generator);
				y = posY(generator);

				if (!snake.IsObjectOnSnake(x, y, powerUp.GetSize()) &&
					!IsObjectOnBlock(x, y, powerUp.GetSize()))
				{
					isAvailable = true;
				}
			}
		}

		std::uniform_int_distribution<int> powerUpIndex(1, 5);

		int upgradeTypeIndex = powerUpIndex(generator);

		std::shared_ptr<MyTexture> powerUpTexture;

		switch (PowerUp::UpgradeType(upgradeTypeIndex))
		{
		case PowerUp::UpgradeType::Slow:
			{
				powerUpTexture = texturesManager.GetTexture(MyTexture::Type::PowerUpSlow);
			}
		break;

		case PowerUp::UpgradeType::Speed:
			{
				powerUpTexture = texturesManager.GetTexture(MyTexture::Type::PowerUpSpeed);
			}
		break;
		case PowerUp::UpgradeType::Eatable:
			{
				powerUpTexture = texturesManager.GetTexture(MyTexture::Type::PowerUpEatableSnake);
			}
		break;
		case PowerUp::UpgradeType::Immunity:
			{
				powerUpTexture = texturesManager.GetTexture(MyTexture::Type::PowerUpImmunity);
			}
		break;
		case PowerUp::UpgradeType::Reversed:
			{
				powerUpTexture = texturesManager.GetTexture(MyTexture::Type::PowerUpReverseSides);
			}
		break;
		}

		powerUp = PowerUp(x, y, powerUpTexture, PowerUp::UpgradeType(upgradeTypeIndex));

		drawableInGameObjects.push_back(&powerUp);
	}
}

void GameManager::GenerateBlock()
{
	if (isPlayingClassicMode)
		return;

	std::random_device device;
	std::mt19937 generator(device());
	std::uniform_real_distribution<float> posX(150.0f, 850.0f); //x e [100,900] y e [250,750]
	std::uniform_real_distribution<float> posY(300.0f, 700.0f);
	std::uniform_int_distribution<int> textureNum(0, 1);

	bool isAvailable = false;
	float x = posX(generator);
	float y = posY(generator);

	int random = textureNum(generator);

	std::shared_ptr<MyTexture> texture;

	if (random == 0)
	{
		texture = texturesManager.GetTexture(MyTexture::Type::BlockH);
	}
	else
	{
		texture = texturesManager.GetTexture(MyTexture::Type::BlockV);
	}

	if (blocks.size() != 0)
	{
		while (!isAvailable)
		{
			x = posX(generator);
			y = posY(generator);

			if (!snake.IsObjectOnSnake(x, y, texture->getSize(), 50.0f) &&
				!powerUp.IsColliding({ x, y }, texture->getSize(), 20.0f) &&
				!pickUp.IsColliding({ x, y }, texture->getSize(), 20.0f) &&
				!IsObjectOnBlock(x, y, texture->getSize()))
			{
				isAvailable = true;
			}
		}
	}

	blocks.push_back(new Block(x, y, texture));
	drawableInGameObjects.push_back(blocks[blocks.size() - 1]);

	// Powodowanie, ¿e snejk zawsze jest na górze wszystkich tekstur bloków widocznych w grze
	drawableInGameObjects.erase(std::remove(drawableInGameObjects.begin(),
		drawableInGameObjects.end(), &snake),
		drawableInGameObjects.end());

	drawableInGameObjects.push_back(&snake);
}

void GameManager::DrawInGameObjects(sf::RenderWindow* window)
{
	for (const auto& obj : drawableInGameObjects)
	{
		obj->Draw(window);
	}
}

void GameManager::DrawEndGameObjects(sf::RenderWindow* window)
{
	for (const auto& obj : drawableEndGameObjects)
	{
		obj->Draw(window);
	}
}

void GameManager::DrawSnakeSelectMenu(sf::RenderWindow* window)
{
	snakeSelectMenu.Draw(window);
}

void GameManager::DrawModeSelectMenu(sf::RenderWindow* window)
{
	modeSelectMenu.Draw(window);
}

void GameManager::GenerateSnakePosition()
{
	std::random_device device;
	std::mt19937 generator(device());
	std::uniform_real_distribution<float> posX(300.0f, 700.0f); //x e [300, 700] y e [400,600]
	std::uniform_real_distribution<float> posY(400.0f, 600.0f);
	std::uniform_int_distribution<int> direction(0, 3); // kierunek

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
	if (snake.IsCollision() && snake.IsEatable())
	{
		scoreManager.SubtractScore(snake.GetNumberOfDecreasedParts());
	}
	else if (!snake.IsInArena(&background) || snake.IsCollision())
	{
		if (!snake.IsImmunited())
		{
			loseScreen.SetScore(scoreManager.GetScore());
			audioManager.PlaySound(MySoundBuffer::Type::Defeat);
			sf::sleep(sf::seconds(1.0f));
			isGameOver = true;

			audioManager.StopSound(MySoundBuffer::Type::GameMusic);
			audioManager.PlaySound(MySoundBuffer::Type::MenuMusic);
		}
	}
	else if (!snake.IsImmunited())
	{
		for (const auto& block : blocks)
		{
			if (block->IsColliding(snake.GetPosition(), snake.GetSize(), -20.0f))
			{
				loseScreen.SetScore(scoreManager.GetScore());
				audioManager.PlaySound(MySoundBuffer::Type::Defeat);
				sf::sleep(sf::seconds(1.0f));
				isGameOver = true;

				audioManager.StopSound(MySoundBuffer::Type::GameMusic);
				audioManager.PlaySound(MySoundBuffer::Type::MenuMusic);
			}
		}
	}
}

bool GameManager::IsGameOver()
{
	return isGameOver;
}

bool GameManager::IsInSnakeSelectMenu()
{
	return isInSnakeSelect;
}

bool GameManager::IsInModeSelectMenu()
{
	return isInModeSelect;
}

void GameManager::CheckIfPickupOrPowerUpIsCollected()
{
	if (pickUp.IsColliding(snake.GetPosition(), snake.GetSize()))
	{
		audioManager.PlaySound(MySoundBuffer::Type::Coin);

		if (isPlayingClassicMode)
		{
			scoreManager.AddScore(10);
		}
		else
		{
			scoreManager.AddScore(15);
		}
		
		isPickUpCollected = true;
		snake.Grow();
		drawableInGameObjects.erase(std::remove(drawableInGameObjects.begin(),
			drawableInGameObjects.end(), &pickUp), drawableInGameObjects.end());

		GeneratePickUp();
	}

	if (powerUp.IsColliding(snake.GetPosition(), snake.GetSize())
		&& powerUp.GetUpgradeType() != PowerUp::UpgradeType::None)
	{
		audioManager.PlaySound(MySoundBuffer::Type::PowerUp);
		clock.restart();
		isPowerUpCollected = true;
		drawableInGameObjects.erase(std::remove(drawableInGameObjects.begin(),
			drawableInGameObjects.end(), &powerUp), drawableInGameObjects.end());

		GiveSnakePower(powerUp.GetUpgradeType());
		powerUpDisplayer.SetTextureAndStartDrawing(powerUp.GetTexture());
		durationTime.restart();
		powerUp.SetPreviousType(powerUp.GetUpgradeType());
		powerUp.SetNone();
	}

	GeneratePowerUp();
}

void GameManager::CheckIfSnakeWasSelected(sf::Vector2i position)
{
	switch (snakeSelectMenu.GetClickedSnake(position))
	{
		case MyTexture::Type::SnakeBigGreen:
		{
			snake.SetTextures(texturesManager.GetTexture(MyTexture::Type::SnakeHeadGreen),
				texturesManager.GetTexture(MyTexture::Type::SnakeBodyGreen));

			isInSnakeSelect = false;
		}
		break;
		case MyTexture::Type::SnakeBigBlue:
		{
			snake.SetTextures(texturesManager.GetTexture(MyTexture::Type::SnakeHeadBlue),
				texturesManager.GetTexture(MyTexture::Type::SnakeBodyBlue));\

			isInSnakeSelect = false;
		}
		break;
		case MyTexture::Type::SnakeBigYellow:
		{
			snake.SetTextures(texturesManager.GetTexture(MyTexture::Type::SnakeHeadYellow),
				texturesManager.GetTexture(MyTexture::Type::SnakeBodyYellow));

			isInSnakeSelect = false;
		}
		break;
		case MyTexture::Type::SnakeBigPink:
		{
			snake.SetTextures(texturesManager.GetTexture(MyTexture::Type::SnakeHeadPink),
				texturesManager.GetTexture(MyTexture::Type::SnakeBodyPink));

			isInSnakeSelect = false;
		}
		break;
		default:
			break;
	}
}

void GameManager::CheckIfModeWasSelected(sf::Vector2i position)
{
	switch (modeSelectMenu.GetClickedMode(position))
	{
		case MyTexture::Type::ClassicArena:
		{
			isPlayingClassicMode = true;
			isInModeSelect = false;

			audioManager.StopSound(MySoundBuffer::Type::MenuMusic);
			audioManager.PlaySound(MySoundBuffer::Type::GameMusic);
		}
		break;
		case MyTexture::Type::UltraArena:
		{
			drawableInGameObjects.push_back(&powerUpDisplayer);
			isPlayingClassicMode = false;
			isInModeSelect = false;

			for (int i = 0; i < howManyBlocks; i++)
			{
				GenerateBlock();
			}

			audioManager.StopSound(MySoundBuffer::Type::MenuMusic);
			audioManager.PlaySound(MySoundBuffer::Type::GameMusic);
		}
		break;
		default:
			break;
	}
}

void GameManager::GiveSnakePower(PowerUp::UpgradeType upgradeType)
{
	switch (upgradeType)
	{
		case PowerUp::UpgradeType::Speed:
		{
			snake.SetSpeed(snake.GetSpeed() * snakeSpeedMultiplier);
		}
		break;
		case PowerUp::UpgradeType::Slow:
		{
			snake.SetSpeed(snake.GetSpeed() / snakeSpeedMultiplier);
		}
		break;
		case PowerUp::UpgradeType::Immunity:
		{
			snake.SetImmunization(true);
			background.SetFlickerStatus(true);

			for (const auto& block : blocks)
			{
				block->SetFlickerStatus(true);
			}
		}
		break;
		case PowerUp::UpgradeType::Reversed:
		{
			SetReversion(true);
		}
		break;
		case PowerUp::UpgradeType::Eatable:
		{
			snake.SetEatablility(true);
		}
		break;
		default:
		break;
	}
}

void GameManager::ResetGame()
{
	scoreManager.ResetScore();
	typeInArea.Reset();
	TurnOffPowerUp();

	timeBetweenPowerUps = -1.0f;

	drawableInGameObjects.erase(std::remove(drawableInGameObjects.begin(), 
		drawableInGameObjects.end(), &pickUp), 
		drawableInGameObjects.end());

	drawableInGameObjects.erase(std::remove(drawableInGameObjects.begin(),
		drawableInGameObjects.end(), &powerUp),
		drawableInGameObjects.end());

	drawableInGameObjects.erase(std::remove(drawableInGameObjects.begin(),
		drawableInGameObjects.end(), &powerUpDisplayer),
		drawableInGameObjects.end());

	for (size_t i = 0; i < blocks.size(); i++)
	{
		drawableInGameObjects.erase(std::remove(drawableInGameObjects.begin(),
			drawableInGameObjects.end(), blocks[i]),
			drawableInGameObjects.end());

		delete blocks[i];
	}

	blocks.clear();

	snake.Reset();

	GenerateSnakePosition();

	isPickUpCollected = true;
	GeneratePickUp();

	isPlayingClassicMode = true;
	isPowerUpCollected = true;
	GeneratePowerUp();
	isGameOver = false;
	isInSnakeSelect = true;
	isInModeSelect = true;
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

AudioManager& GameManager::GetAudioManager()
{
	return audioManager;
}

void GameManager::CheckPowerUpDuration()
{
	if (durationTime.getElapsedTime().asSeconds() > powerUpDuration)
	{
		TurnOffPowerUp();
	}
}

void GameManager::TurnOffPowerUp()
{
	if (powerUp.GetPreviousType() == PowerUp::UpgradeType::Speed)
	{
		snake.SetSpeed(snake.GetSpeed() / snakeSpeedMultiplier);
	}
	else if (powerUp.GetPreviousType() == PowerUp::UpgradeType::Slow)
	{
		snake.SetSpeed(snake.GetSpeed() * snakeSpeedMultiplier);
	}
	else if (powerUp.GetPreviousType() == PowerUp::UpgradeType::Immunity)
	{
		background.SetFlickerStatus(false);

		for (const auto& block : blocks)
		{
			block->SetFlickerStatus(false);
		}

		snake.SetImmunization(false);
	}
	else if (powerUp.GetPreviousType() == PowerUp::UpgradeType::Reversed)
	{
		SetReversion(false);
	}
	else if (powerUp.GetPreviousType() == PowerUp::UpgradeType::Eatable)
	{
		snake.SetEatablility(false);
	}

	powerUp.SetPreviousType(PowerUp::UpgradeType::None);
	powerUpDisplayer.StopDrawing();
}

bool const GameManager::IsReversed() const
{
	return isReversed;
}

void GameManager::SetReversion(bool val)
{
	isReversed = val;
}

void GameManager::FlickerObjects()
{
	background.Flicker();
	powerUpDisplayer.Flicker();

	for (const auto& block : blocks)
	{
		block->Flicker();
	}
}

GameManager::~GameManager()
{
	for (size_t i = 0; i < blocks.size(); i++)
	{
		delete blocks[i];
	}
}