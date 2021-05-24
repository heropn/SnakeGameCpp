#pragma once
#include <iostream>
#include <string>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
using namespace std;

class IDrawable
{
public:
    virtual void Draw(sf::RenderWindow* window) = 0;
};

class Button : public IDrawable {
private:
    sf::Font font;
    sf::Text text;
public:
    sf::RectangleShape rectangle;
    Button(string content, float position_x, float position_y);
    void Draw(sf::RenderWindow* window);
};

class Header : public IDrawable {
private:
        sf::Font font;
        sf::Text text;
public:
    
    Header(string content);
    void Draw(sf::RenderWindow* window);
};