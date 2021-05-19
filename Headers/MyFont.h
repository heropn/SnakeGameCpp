#pragma once
#include <SFML/Graphics.hpp>

class MyFont : public sf::Font
{
public:
	enum class Type
	{
		Arial,
	};

private:
	Type type;

public:
	MyFont(Type type);

	const Type GetType() const;
};