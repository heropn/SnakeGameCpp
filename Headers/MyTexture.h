#pragma once
#include <SFML/Graphics.hpp>

class MyTexture : public sf::Texture
{
public:
	// Typy tekstur za³adowanych w pamiêæ programu
	enum class Type
	{
		SnakeHeadGreen,
		SnakeBodyGreen,
		SnakeBigGreen,
		SnakeHeadPink,
		SnakeBodyPink,
		SnakeBigPink,
		SnakeHeadBlue,
		SnakeBodyBlue,
		SnakeBigBlue,
		SnakeHeadYellow,
		SnakeBodyYellow,
		SnakeBigYellow,
		Apple,
		Arena,
		Menu,
		HelpScreen,
		HelpScreen2,
		CreditsScreen,
		PowerUpSpeed,
		PowerUpImmunity,
		PowerUpEatableSnake,
		PowerUpReverseSides,
		PowerUpSlow,
		BlockV,
		BlockH,
		ClassicArena,
		UltraArena,
		None
	};

private:
	Type type;

public:
	// Konstruktor parametryczny
	// Ustawa typ Tekstury
	MyTexture(Type type);

	// Zwraca typ tekstury
	const Type GetType() const;
};