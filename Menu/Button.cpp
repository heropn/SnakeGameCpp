#include "Button.h"

Button::Button(string content, float position_x, float position_y) {
    rectangle.setFillColor(sf::Color::Green);
    rectangle.setSize(sf::Vector2f(350, 65));
    rectangle.setPosition(position_x, position_y);

    font.loadFromFile("arial.ttf");
    text.setString(content);
    text.setFont(font);
    text.setCharacterSize(50);

    float xPos = (position_x + 350 / 2) - (text.getLocalBounds().width / 2); // wspó³rzêdne tekstu, ustawione ¿eby wyœrodkowaæ napis wzglêdem przycisku
    float yPos = (position_y + 65 / 2) - (text.getLocalBounds().height / 2) - 12.5; // -12.5 = 1/4 rozmiaru czcionki 
    text.setPosition(xPos, yPos);
}

void Button::Draw(sf::RenderWindow* window) {
    window->draw(rectangle);
    window->draw(text);
}