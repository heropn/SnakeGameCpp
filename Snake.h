#pragma once
#include <SFML/Graphics.hpp>
#include "Background.h"

class Snake
{
public:
	enum class Direction{Top,Right,Bottom,Left};
private:
	float posX;
	float posY;
	float speed;
	sf::RectangleShape shape;
	int size;
	Direction direction;
	std::vector<sf::Vector2f>positions;
	void SetSnakesProperties();
public:
	Snake();
	Snake(float x, float y,Direction direction);
	void Draw(sf::RenderWindow* window);
	void SetSpeed(int speed);
	bool IsInArena(Background* background);
	void SetDirection(Direction direction);
	sf::Vector2f GetPosition();
	Direction GetDirection();
	sf::RectangleShape GetShape();
	bool IsCollision();
	void Move();
	void Grow();
};