#pragma once
#include <SFML/Graphics.hpp>

class MyTexture : public sf::Texture
{
public:
	enum class Type
	{
		SnakeHeadGreen,
		SnakeBodyGreen,
		SnakeHeadPink,
		SnakeBodyPink,
		SnakeHeadBlue,
		SnakeBodyBlue,
		SnakeHeadYellow,
		SnakeBodyYellow,
		Apple,
		None
	};

private:
	Type type;

public:
	// Konstruktor domyœlny
	MyTexture(Type type);

	// Zwraca typ tekstury
	const Type GetType() const;
};