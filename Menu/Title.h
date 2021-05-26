#pragma once
#include "IDrawable.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
using namespace std;

class Title : public IDrawable {
private:
    sf::Font font;
    sf::Text text;
public:
    Title(string content);
    void Draw(sf::RenderWindow* window);
};