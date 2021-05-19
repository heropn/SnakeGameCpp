#include "..\Headers\FontsManager.h"
#include <iostream>

FontsManager::FontsManager()
{
	LoadAllFonts();
}

const std::shared_ptr<MyFont> FontsManager::GetFont(MyFont::Type type) const
{
	for (const auto& font : fontsPointers)
	{
		if (font->GetType() == type)
			return font;
	}

	return nullptr;
}

void FontsManager::LoadAllFonts()
{
	for (const auto& s : filesPaths)
		AddFont(s.filePath, s.type);
}

void FontsManager::AddFont(std::string fileName, MyFont::Type type)
{
	std::shared_ptr<MyFont> fontPtr(new MyFont(type));

	if (!fontPtr->loadFromFile(fileName))
	{
		std::cout << "Couldn't load file: " << fileName << std::endl;
		return;
	}
	else
	{
		fontsPointers.push_back(fontPtr);
	}
}