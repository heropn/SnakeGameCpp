#include "..\Headers\SoundBufferManager.h"
#include <iostream>

SoundBufferManager::SoundBufferManager()
{
	LoadAllSoundBuffers();
}

void SoundBufferManager::LoadAllSoundBuffers()
{
	for (const auto& s : filesPaths)
		AddSoundBuffer(s.filePath, s.type);
}

void SoundBufferManager::AddSoundBuffer(std::string fileName, MySoundBuffer::Type type)
{
	std::shared_ptr<MySoundBuffer> soundBuffer(new MySoundBuffer(type));

	if (!soundBuffer->loadFromFile(fileName))
	{
		std::cout << "Couldn't load file: " << fileName << std::endl;
		return;
	}
	else
	{
		soundBuffersPointers.push_back(soundBuffer);
	}
}

const std::vector<std::shared_ptr<MySoundBuffer>>& SoundBufferManager::GetVector() const
{
	return soundBuffersPointers;
}

const std::shared_ptr<MySoundBuffer> SoundBufferManager::GetSoundBuffer(MySoundBuffer::Type type) const
{
	for (const auto& texture : soundBuffersPointers)
	{
		if (texture->GetType() == type)
			return texture;
	}

	return nullptr;
}
