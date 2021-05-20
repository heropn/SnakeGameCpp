#pragma once
#include <SFML/Audio.hpp>

class MySoundBuffer : public sf::SoundBuffer
{
public:
	enum class Type
	{
		Coin,
		Defeat
	};

private:
	Type type;

public:
	MySoundBuffer(Type type);

	const Type GetType() const;
};