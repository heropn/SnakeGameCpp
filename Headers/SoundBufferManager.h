#pragma once
#include "MySoundBuffer.h"

class SoundBufferManager
{
private:
	// Struktura wspomagaj¹ca ³adowanie danych z plików
	struct SoundBufferInfo
	{
		std::string filePath;
		MySoundBuffer::Type type;
	};

	std::vector<std::shared_ptr<MySoundBuffer>> soundBuffersPointers;

	// Przechowuje wszystkie SoundBuffery do za³adowania
	std::vector<SoundBufferInfo> filesPaths
	{
		{".\\Sounds\\Coin.wav", MySoundBuffer::Type::Coin},
		{".\\Sounds\\Defeat.wav", MySoundBuffer::Type::Defeat},
		{".\\Sounds\\PowerUp.wav", MySoundBuffer::Type::PowerUp},
		{".\\Sounds\\MusicMenu.wav", MySoundBuffer::Type::MenuMusic},
		{".\\Sounds\\MusicGame.wav", MySoundBuffer::Type::GameMusic}
	};

public:
	// Konstruktor domyœlny
	SoundBufferManager();

	// £aduje wszystkie podane SoundBuffer'y
	void LoadAllSoundBuffers();

	// Zwraca dany SoundBuffer
	const std::shared_ptr<MySoundBuffer> GetSoundBuffer(MySoundBuffer::Type type) const;

	// Zwraca wektor wszystkich SoundBuffer'ów
	const std::vector<std::shared_ptr<MySoundBuffer>>& GetVector() const;

private:
	// Dodaje nowy podany SoundBuffer
	void AddSoundBuffer(std::string fileName, MySoundBuffer::Type type);
};