#pragma once
#include "MySoundBuffer.h"

class SoundBufferManager
{
private:
	struct SoundBufferInfo
	{
		std::string filePath;
		MySoundBuffer::Type type;
	};

	std::vector<std::shared_ptr<MySoundBuffer>> soundBuffersPointers;

	// Przechowuje wszystkie tekstury do za³adowania
	std::vector<SoundBufferInfo> filesPaths
	{
		{"coin.wav", MySoundBuffer::Type::Coin}
	};

public:
	// Konstruktor domyœlny
	SoundBufferManager();

	// £aduje wszystkie podane tekstury
	void LoadAllSoundBuffers();

	// Zwraca dan¹ teksturê
	const std::shared_ptr<MySoundBuffer> GetSoundBuffer(MySoundBuffer::Type type) const;

	const std::vector<std::shared_ptr<MySoundBuffer>>& GetVector() const;

private:
	// Dodaje podan¹ teksturê
	void AddSoundBuffer(std::string fileName, MySoundBuffer::Type type);
};