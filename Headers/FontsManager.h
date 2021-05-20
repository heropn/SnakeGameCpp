#pragma once
#include "MyFont.h"

class FontsManager
{
private:
	// Struktura do ³adowania czcionek
	struct FontInfo
	{
		std::string filePath;
		MyFont::Type type;
	};

	std::vector<std::shared_ptr<MyFont>> fontsPointers;

	// Wektor wszystkich czcionek do za³adowania
	std::vector<FontInfo> filesPaths
	{
		{".\\Fonts\\arial.ttf", MyFont::Type::Arial},
		{".\\Fonts\\snake.ttf", MyFont::Type::Snake},
		{".\\Fonts\\lostIsland.ttf", MyFont::Type::LostIsland}
	};

public:
	// Konstruktor domyœlny
	FontsManager();

	// Zwraca dan¹ czcionkê
	const std::shared_ptr<MyFont> GetFont(MyFont::Type type) const;

private:
	// £aduje wszystkie podane czcionki
	void LoadAllFonts();

	// Dodaje now¹ czcionkê
	void AddFont(std::string fileName, MyFont::Type type);
};