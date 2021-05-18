#include "..\Headers\TexturesManager.h"
#include <iostream>

TexturesManager::TexturesManager() 
{
	LoadAllTextures();
}

void TexturesManager::LoadAllTextures()
{
	for (const auto& s : filesPaths)
		AddTexture(s.filePath, s.type);
}

void TexturesManager::AddTexture(std::string fileName, MyTexture::Type type)
{
	std::shared_ptr<MyTexture> texture(new MyTexture(type));

	if (!texture->loadFromFile(fileName))
	{
		std::cout << "Couldn't load file: " << fileName << std::endl;
		return;
	}
	else
	{
		texture->setSmooth(true);
		texturesPointers.push_back(texture);
	}
}

const std::shared_ptr<MyTexture> TexturesManager::GetTexture(MyTexture::Type type) const
{
	for (const auto& texture : texturesPointers)
	{
		if (texture->GetType() == type)
			return texture;
	}

	return nullptr;
}
