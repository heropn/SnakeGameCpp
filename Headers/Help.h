#pragma once
#include "IDrawable.h"
#include "MyTexture.h"
#include "Button.h"
#include "MyFont.h"

class Help : public IDrawable {
	sf::Sprite help;
	sf::Texture helpTexture;
	Button back;
	std::shared_ptr<MyFont> fontTitleText;
	public:
		Help();
		void Draw(sf::RenderWindow* window);
		bool CheckIfButtonWasClicked(sf::Vector2i vec);
		void setFont(std::shared_ptr<MyFont> fontTitleText);
};