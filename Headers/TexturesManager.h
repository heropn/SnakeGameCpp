#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "MyTexture.h"

class TexturesManager
{
private:
	struct TextureInfo
	{
		std::string filePath;
		MyTexture::Type type;
	};

	std::vector<std::shared_ptr<MyTexture>> texturesPointers;

	// Przechowuje wszystkie tekstury do załadowania
	std::vector<TextureInfo> filesPaths
	{
		{".\\Textures\\SnakeHead-Green.png", MyTexture::Type::SnakeHeadGreen},
		{".\\Textures\\SnakeBody-Green.png", MyTexture::Type::SnakeBodyGreen},
		{".\\Textures\\SnakeBig-Green.png", MyTexture::Type::SnakeBigGreen},
		{".\\Textures\\SnakeBody-Pink.png", MyTexture::Type::SnakeBodyPink},
		{".\\Textures\\SnakeHead-Pink.png", MyTexture::Type::SnakeHeadPink},
		{".\\Textures\\SnakeBig-Pink.png", MyTexture::Type::SnakeBigPink},
		{".\\Textures\\SnakeBody-Blue.png", MyTexture::Type::SnakeBodyBlue},
		{".\\Textures\\SnakeHead-Blue.png", MyTexture::Type::SnakeHeadBlue},
		{".\\Textures\\SnakeBig-Blue.png", MyTexture::Type::SnakeBigBlue},
		{".\\Textures\\SnakeBody-Yellow.png", MyTexture::Type::SnakeBodyYellow},
		{".\\Textures\\SnakeHead-Yellow.png", MyTexture::Type::SnakeHeadYellow},
		{".\\Textures\\SnakeBig-Yellow.png", MyTexture::Type::SnakeBigYellow},
		{".\\Textures\\Apple.png", MyTexture::Type::Apple},
		{".\\Textures\\Arena.png", MyTexture::Type::Arena},
		{".\\Textures\\Menu.png", MyTexture::Type::Menu},
		{".\\Textures\\Credits.png", MyTexture::Type::CreditsScreen},
		{".\\Textures\\HelpScreen.png", MyTexture::Type::HelpScreen},
		{".\\Textures\\SpeedPowerUp.png", MyTexture::Type::PowerUpSpeed},
		{".\\Textures\\ReversePowerUp.png", MyTexture::Type::PowerUpReverseSides},
		{".\\Textures\\EatablePowerUp.png", MyTexture::Type::PowerUpEatableSnake},
		{".\\Textures\\ImmunityPowerUp.png", MyTexture::Type::PowerUpImmunity},
		{".\\Textures\\SlowPowerUp.png", MyTexture::Type::PowerUpSlow},
		{".\\Textures\\BlockHorizontal.png", MyTexture::Type::BlockH},
		{".\\Textures\\BlockVertical.png", MyTexture::Type::BlockV},
		{".\\Textures\\ClassicArena.png", MyTexture::Type::ClassicArena},
		{".\\Textures\\UltraArena.png", MyTexture::Type::UltraArena},
		{".\\Textures\\HelpScreen2.png", MyTexture::Type::HelpScreen2},
	};

public:
	// Konstruktor domyślny
	TexturesManager();
	
	// Ładuje wszystkie podane tekstury
	void LoadAllTextures();

	// Zwraca daną teksturę
	const std::shared_ptr<MyTexture> GetTexture(MyTexture::Type type) const;

private:
	// Dodaje podaną teksturę
	void AddTexture(std::string fileName, MyTexture::Type type);
};
