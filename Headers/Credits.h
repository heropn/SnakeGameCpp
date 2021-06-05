#pragma once
#include "IDrawable.h"
#include "MyTexture.h"
#include "Button.h"
#include "MyFont.h"

class Credits : public IDrawable {
	sf::Sprite Pauli;
	sf::Texture PauliTexture;
	Button back;
	std::shared_ptr<MyFont> fontTitleText;
public:
	Credits();
	void Draw(sf::RenderWindow* window);
	bool CheckIfButtonWasClicked(sf::Vector2i vec);
	void setFont(std::shared_ptr<MyFont> fontTitleText);
};