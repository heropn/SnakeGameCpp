#pragma once
#include "MyFont.h"

class FontsManager
{
private:
	struct FontInfo
	{
		std::string filePath;
		MyFont::Type type;
	};

	std::vector<std::shared_ptr<MyFont>> fontsPointers;
	std::vector<FontInfo> filesPaths
	{
		{".\\Fonts\\arial.ttf", MyFont::Type::Arial},
	};

public:
	FontsManager();
	const std::shared_ptr<MyFont> GetFont(MyFont::Type type) const;

private:
	void LoadAllFonts();
	void AddFont(std::string fileName, MyFont::Type type);
};