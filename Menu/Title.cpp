#include "Title.h"

Title::Title(string content) {
    font.loadFromFile("arial.ttf");
    text.setString(content);
    text.setFont(font);
    text.setCharacterSize(70);

    float xPos = (1000 / 2) - (text.getLocalBounds().width / 2); //wyœrodkowanie napisu wzglêdem osi X
    float yPos = 50;
    text.setFillColor(sf::Color::Green);
    text.setPosition(xPos, yPos);
}

void Title::Draw(sf::RenderWindow* window) {
    window->draw(text);
}