#pragma once
#include <SFML/Audio.hpp>
#include "SoundBufferManager.h"

class AudioManager
{
private:
	// Struktura przechowuj¹ca dŸwiêk i jego buffer
	struct MySound
	{
		sf::Sound sound;
		std::shared_ptr<MySoundBuffer> soundBuffer;

		// konstruktor parametryczny dodaj¹cy SoundBuffer do Sound'a
		MySound(std::shared_ptr<MySoundBuffer> soundBuffer);

		// Gra dŸwiêk, który zawiera
		void Play();

		// Zwraca typ SoundBuffer'a
		const MySoundBuffer::Type GetType() const;
	};

	SoundBufferManager soundBufferManager;
	std::vector<MySound> sounds;

public:
	// Konstruktor domyœlny
	// Tworzy obiekt MySound dla ka¿dego sound buffera
	// Zawartego w SoundBufferManager'ze
	AudioManager();

	// Gra podany typ dŸwieku
	const void PlaySound(MySoundBuffer::Type type);

	// Przestaje graæ podany typ dŸwiêku
	const void StopSound(MySoundBuffer::Type type);

private:
	// Ustawia odpowiednie g³oœnoœci wszystkim dŸwiêkom
	void SetSoundDetails();
};
