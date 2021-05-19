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
		SnakeBodyPink
	};

private:
	Type type;

public:
	MyTexture(Type type);

	const Type GetType() const;
};