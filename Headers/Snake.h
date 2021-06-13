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
	bool immunited;
	bool isEatable;
	int numberOfDecresedParts;

public:
	// Konstruktor domyœlny, ustawia odpowiednie wartoœci dla zmiennych
	Snake();

	// Ustawia tekstury snake'a
	void SetTextures(std::shared_ptr<MyTexture> headTexture, std::shared_ptr<MyTexture> bodyTexture);
	
	// Rysuje snake'a na ekranie
	void Draw(sf::RenderWindow* window);

	// Ustawia prêdkoœæ snake'a
	void SetSpeed(float speed);

	// Zmiana kierunku poruszania siê snake'a
	void SetDirection(Direction direction);

	// Ustawia rotacje sprite'a znale¿nego od kierunku snake'a
	void SetSpriteRotation();

	// Ustawia pozycje snake'a
	void SetPosition(float x, float y);

	// Ustawia niewra¿liwoœæ
	void SetImmunization(bool val);

	// Ustawia mo¿liwoœæ zjadania siebie
	void SetEatablility(bool val);

	// Zwraca true, jeœli snake jest niewra¿liwy
	bool const IsImmunited() const;
	
	// Zwraca true, jeœli snake mo¿e siebie jeœæ
	bool const IsEatable() const;

	// Zmienia pozycje snake'a 
	void Move();

	// Zwiêksza wielkoœæ snake'a i jego prêdkoœæ
	void Grow();

	// Resetuje wszystkie ustawienia snake'a
	void Reset();

	// Zwraca pozycje g³owy snake'a
	const sf::Vector2f& GetPosition() const;

	// Zwraca rozmiar spritu snake'a
	const sf::Vector2u GetSize() const;
	
	// Zwraca liczbê zjedzon¹ przez siebie
	const int GetNumberOfDecreasedParts() const;

	// Zwraca kierunek snake'a
	const Direction GetDirection() const;

	// Zwraca sprite'a snake'a
	const sf::Sprite& GetSprite() const;

	// Zwraca prêdkoœæ snake'a
	const float GetSpeed() const;

	// Funkcja sprawdza, czy Snake znajduje siê w polu gry
	bool IsInArena(Background* background);

	// Sprawdza, czy dosz³o do kolizji snake'a (czy zjad³ siebie)
	bool IsCollision();

	// Sprawdza, czy potencjalny PickUp jest na snake'u
	bool IsObjectOnSnake(float posX, float posY, sf::Vector2u pickUpSize, float additionalDistance = 0);
private:
	// Ustawia w³aœciwoœci snake'a
	void SetSpriteProperties();
};