#include "TexturesManager.h"

TexturesManager::TexturesManager() {}

void TexturesManager::LoadAllTextures()
{
	for (auto s : filesPaths)
		AddTexture(s.filePath, s.type);
}

void TexturesManager::AddTexture(std::string fileName, MyTexture::Type type)
{
	std::shared_ptr<MyTexture> texture(new MyTexture(type));

	if (!texture->loadFromFile(fileName))
	{
		Debug("ERROR OPENING FILE: " + fileName);
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
	for (auto texture : texturesPointers)
	{
		if (texture->GetType() == type)
			return texture;
	}

	return nullptr;
}
