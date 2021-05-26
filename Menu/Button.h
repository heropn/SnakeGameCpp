#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "IDrawable.h"
using namespace std;

class Button : public IDrawable {
private:
    sf::Font font;
    sf::Text text;
public:
    Button(string content, float position_x, float position_y);
    sf::RectangleShape rectangle;
    void Draw(sf::RenderWindow* window);
};