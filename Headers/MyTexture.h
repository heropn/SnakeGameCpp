#pragma once
#include <SFML/Graphics.hpp>

class MyTexture : public sf::Texture
{
public:
	enum class Type
	{
		SnakeHead,
		SnakeBody
	};

private:
	Type type;

public:
	MyTexture(Type type);

	const Type GetType() const;
};