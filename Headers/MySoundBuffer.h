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
		Defeat
	};

private:
	Type type;

public:
	// Konstruktor domyœlny
	MySoundBuffer(Type type);

	// Zwraca typ SoundBuffera
	const Type GetType() const;
};