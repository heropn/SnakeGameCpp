#pragma once
#include <SFML/Audio.hpp>

class MySoundBuffer : public sf::SoundBuffer
{
public:
	// Typy SoundBuffer'ów
	enum class Type
	{
		Coin,
		PowerUp,
		Defeat,
		MenuMusic,
		GameMusic
	};

private:
	Type type;

public:
	// Konstruktor parametryczny
	// Ustawa typ SoundBuffera
	MySoundBuffer(Type type);

	// Zwraca typ SoundBuffera
	const Type GetType() const;
};