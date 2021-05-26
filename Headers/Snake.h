#pragma once
#include <SFML/Graphics.hpp>
#include "Background.h"
#include "MyTexture.h"
#include "IDrawable.h"

class Snake : public IDrawable
{
public:
	enum class Direction{Top,Right,Bottom,Left};

private:
	float posX;
	float posY;
	float speed;
	unsigned int size;
	unsigned int increasingSize;
	std::shared_ptr<MyTexture> headTexture;
	std::shared_ptr<MyTexture> bodyTexture;
	sf::Sprite sprite;
	Direction direction;
	std::vector<sf::Vector2f>positions;

public:
	// Konstruktor domy�lny
	Snake();

	void SetTextures(std::shared_ptr<MyTexture> headTexture, std::shared_ptr<MyTexture> bodyTexture);
	
	// Rysuje snake'a na ekranie
	void Draw(sf::RenderWindow* window);

	// Ustawia pr�dko�� snake'a
	void SetSpeed(float speed);

	// Zmiana kierunku poruszania si� snake'a
	void SetDirection(Direction direction);

	// Ustawia rotacje sprite'a
	void SetSpriteRotation();

	// Ustawia pozycje snake'a
	void SetPosition(float x, float y);

	// Zmienia pozycje snake'a 
	void Move();

	// Zwi�ksza wielko�� snake'a i jego pr�dko��
	void Grow();

	void Reset();

	// Zwraca pozycje g�owy snake'a
	const sf::Vector2f& GetPosition() const;

	// Zwraca rozmiar spritu snake'a
	const sf::Vector2u GetSize() const;

	// Zwraca kierunek snake'a
	const Direction GetDirection() const;

	// Zwraca sprite'a snake'a
	const sf::Sprite& GetSprite() const;

	// Funkcja sprawdza, czy Snake znajduje si� w polu gry
	bool IsInArena(Background* background);

	// Sprawdza, czy dosz�o do kolizji snake'a (czy zjad� siebie)
	bool IsCollision();

	// Sprawdza, czy potencjalny PickUp jest na snake'u
	bool IsPickUpOnSnake(float posX, float posY, sf::Vector2u pickUpSize);
private:
	// Ustawia w�a�ciwo�ci snake'a
	void SetSpriteProperties();
};