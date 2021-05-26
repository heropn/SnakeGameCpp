#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class IDrawable
{
public:
    virtual void Draw(sf::RenderWindow* window) = 0;
};