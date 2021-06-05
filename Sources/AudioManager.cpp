#include "..\Headers\AudioManager.h"

AudioManager::MySound::MySound(std::shared_ptr<MySoundBuffer> soundBuffer) : soundBuffer(soundBuffer)
{
	sound.setBuffer(*this->soundBuffer);
}

void AudioManager::MySound::Play()
{
	sound.play();
}

const MySoundBuffer::Type AudioManager::MySound::GetType() const
{
	return soundBuffer->GetType();
}

AudioManager::AudioManager()
{
	for (const auto& sb : soundBufferManager.GetVector())
	{
		sounds.push_back(sb);
	}

	SetSoundDetails();
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

const void AudioManager::StopSound(MySoundBuffer::Type type)
{
	for (auto& mySound : sounds)
	{
		if (mySound.GetType() == type)
		{
			mySound.sound.stop();
			break;
		}
	}
}

void AudioManager::SetSoundDetails()
{
	for (auto& mySound : sounds)
	{
		switch (mySound.GetType())
		{
			case MySoundBuffer::Type::Coin:
			{
				mySound.sound.setVolume(100.0f);
			}
			break;
			case MySoundBuffer::Type::PowerUp:
			{
				mySound.sound.setVolume(90.0f);
			}
			break;
			case MySoundBuffer::Type::Defeat:
			{
				mySound.sound.setVolume(100.0f);
			}
			break;
			case MySoundBuffer::Type::MenuMusic:
			{
				mySound.sound.setVolume(10.0f);
				mySound.sound.setLoop(true);
			}
			break;
			case MySoundBuffer::Type::GameMusic:
			{
				mySound.sound.setVolume(10.0f);
				mySound.sound.setLoop(true);
			}
			break;
			default:
				break;
		}
	}
}