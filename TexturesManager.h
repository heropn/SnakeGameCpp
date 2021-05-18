#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "MyTexture.h"
#include "Debug.h"

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
		{"Textures\\player.png", MyTexture::Type::Player},
		{"Textures\\pickup.png", MyTexture::Type::PickUp},
		{"Textures\\heart.png", MyTexture::Type::Heart},
		{"Textures\\button.png", MyTexture::Type::Button}
	};

public:
	TexturesManager();
	
	void LoadAllTextures();

	const std::shared_ptr<MyTexture> GetTexture(MyTexture::Type type) const;

private:
	void AddTexture(std::string fileName, MyTexture::Type type);
};
