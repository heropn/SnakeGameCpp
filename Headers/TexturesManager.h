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

	// Przechowuje wszystkie tekstury do za³adowania
	std::vector<TextureInfo> filesPaths
	{
		{".\\Textures\\SnakeHead.png", MyTexture::Type::SnakeHeadGreen},
		{".\\Textures\\SnakeBody.png", MyTexture::Type::SnakeBodyGreen},
		{".\\Textures\\SnakeBody-Pink.png", MyTexture::Type::SnakeBodyPink},
		{".\\Textures\\SnakeHead-Pink.png", MyTexture::Type::SnakeHeadPink}
	};

public:
	// Konstruktor domyœlny
	TexturesManager();
	
	// £aduje wszystkie podane tekstury
	void LoadAllTextures();

	// Zwraca dan¹ teksturê
	const std::shared_ptr<MyTexture> GetTexture(MyTexture::Type type) const;

private:
	// Dodaje podan¹ teksturê
	void AddTexture(std::string fileName, MyTexture::Type type);
};
