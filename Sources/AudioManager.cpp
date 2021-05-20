#include "..\Headers\AudioManager.h"

AudioManager::Sound::Sound(std::shared_ptr<MySoundBuffer> soundBuffer) : soundBuffer(soundBuffer)
{
	sound.setBuffer(*this->soundBuffer);
}

void AudioManager::Sound::Play()
{
	sound.play();
}

const MySoundBuffer::Type AudioManager::Sound::GetType() const
{
	return soundBuffer->GetType();
}

AudioManager::AudioManager()
{
	for (const auto& sb : soundBufferManager.GetVector())
	{
		sounds.push_back(sb);
	}
}

const void AudioManager::PlaySound(MySoundBuffer::Type type)
{
	for (auto& sound : sounds)
	{
		if (sound.GetType() == type)
		{
			sound.Play();
			break;
		}
	}
}