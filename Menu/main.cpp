#include "MainMenu.h"

int main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(1000, 800), "Snake Game", sf::Style::Close, settings);
   

    window.setVerticalSyncEnabled(true);
    window.setKeyRepeatEnabled(false);
    window.setFramerateLimit(60);

    MainMenu* menu = new MainMenu(window);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            else {
                menu->checkIfButtonWasClicked(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
            }
        }
        window.clear(sf::Color::Black);

       //rysowanie wszystkich elementów
        menu->drawButtonsAndTitle();
        window.display();
    }

    return 0;
}