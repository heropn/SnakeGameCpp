#pragma once
#include <SFML/Graphics.hpp>
#include "Background.h"
#include "MyTexture.h"

class Snake
{
public:
	enum class Direction{Top,Right,Bottom,Left};

private:
	float posX;
	float posY;
	float speed;
	std::shared_ptr<MyTexture> headTexture;
	std::shared_ptr<MyTexture> bodyTexture;
	sf::Sprite sprite;
	int size;
	Direction direction;
	std::vector<sf::Vector2f>positions;

public:
	// Konstruktor domyœlny
	Snake();

	// Konstruktor parametryczny
	Snake(std::shared_ptr<MyTexture> headTexture, std::shared_ptr<MyTexture> bodyTexture);
	
	// Rysuje snake'a na ekranie
	void Draw(sf::RenderWindow* window);

	// Ustawia prêdkoœæ snake'a
	void SetSpeed(int speed);

	// Funkcja sprawdza, czy Snake znajduje siê w polu gry
	bool IsInArena(Background* background);

	// Zmiana kierunku poruszania siê snake'a
	void SetDirection(Direction direction);

	// Ustawia rotacje sprite'a
	void SetSpriteRotation();

	// Ustawia pozycje snake'a
	void SetPosition(float x, float y);

	// Zwraca pozycje g³owy snake'a
	const sf::Vector2f& GetPosition() const;

	// Zwraca rozmiar spritu snake'a
	const sf::Vector2u& GetSize() const;

	// Zwraca kierunek snake'a
	const Direction GetDirection() const;

	// Zwraca sprite'a snake'a
	const sf::Sprite& GetSprite() const;

	// Sprawdza, czy dosz³o do kolizji snake'a (czy zjad³ siebie)
	bool IsCollision();

	// Zmienia pozycje snake'a 
	void Move();

	// Zwiêksza wielkoœæ snake'a i jego prêdkoœæ
	void Grow();

private:

	// Ustawia w³aœciwoœci snake'a
	void SetSpriteProperties();
};