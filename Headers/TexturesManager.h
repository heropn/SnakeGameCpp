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
	std::vector<TextureInfo> filesPaths
	{
		{".\\Textures\\SnakeHead.png", MyTexture::Type::SnakeHeadGreen},
		{".\\Textures\\SnakeBody.png", MyTexture::Type::SnakeBodyGreen},
		{".\\Textures\\SnakeBody-Pink.png", MyTexture::Type::SnakeBodyPink},
		{".\\Textures\\SnakeHead-Pink.png", MyTexture::Type::SnakeHeadPink}
	};

public:
	TexturesManager();
	
	void LoadAllTextures();

	const std::shared_ptr<MyTexture> GetTexture(MyTexture::Type type) const;

private:
	void AddTexture(std::string fileName, MyTexture::Type type);
};
