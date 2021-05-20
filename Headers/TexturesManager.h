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

	// Przechowuje wszystkie tekstury do za�adowania
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
		{".\\Textures\\Apple.png", MyTexture::Type::Apple}
	};

public:
	// Konstruktor domy�lny
	TexturesManager();
	
	// �aduje wszystkie podane tekstury
	void LoadAllTextures();

	// Zwraca dan� tekstur�
	const std::shared_ptr<MyTexture> GetTexture(MyTexture::Type type) const;

private:
	// Dodaje podan� tekstur�
	void AddTexture(std::string fileName, MyTexture::Type type);
};
