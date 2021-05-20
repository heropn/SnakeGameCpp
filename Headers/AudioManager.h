#pragma once
#include <SFML/Audio.hpp>
#include "SoundBufferManager.h"

class AudioManager
{
private:
	struct Sound
	{
		sf::Sound sound;
		std::shared_ptr<MySoundBuffer> soundBuffer;

		Sound(std::shared_ptr<MySoundBuffer> soundBuffer);

		void Play();

		const MySoundBuffer::Type GetType() const;
	};

	SoundBufferManager soundBufferManager;
	std::vector<Sound> sounds;

public:
	AudioManager();

	const void PlaySound(MySoundBuffer::Type type);
};
