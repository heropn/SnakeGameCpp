#include "menu.h"

int main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(1000, 800), "Snake Game", sf::Style::Close, settings);
   

    window.setVerticalSyncEnabled(true);
    window.setKeyRepeatEnabled(false);
    window.setFramerateLimit(60);

  
    float x_offset = 550, y_offset_start = 250, y_offset = 100; //y_offset_start - startowe odsuniêcie od góry, y_offset - odstêp pomiêdzy kolejnymi przyciskami
    Button start("PLAY", x_offset, y_offset_start);
    Button highscore("Highscores", x_offset, y_offset+y_offset_start);
    Button help("Help", x_offset, 2*y_offset+y_offset_start);
    Button credits("Credits", x_offset, 3*y_offset+y_offset_start);
    Button quit("Exit", x_offset, 4 * y_offset+y_offset_start);
    Header snake("Snejk");
    

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            //warunki sprawdzaj¹ce, czy kursor jest w obrêbie przycisku, a jeœli tak, to czy zosta³ naciœniêty
            else if (start.rectangle.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                        cout << "Graj" << endl;
                    }
            }
            else if (highscore.rectangle.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    cout << "Najlepsze wyniki" << endl;
                }
            }
            else if (help.rectangle.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    cout << "Pomoc" << endl;
                }
            }
            else if (credits.rectangle.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    cout << "Creditsy" << endl;
                }
            }
            else if (quit.rectangle.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    cout << "Exit" << endl;
                    window.close();
                }
            }
        }
        window.clear(sf::Color::Black);

       //rysowanie wszystkich elementów
        snake.Draw(&window);
        start.Draw(&window);
        highscore.Draw(&window);
        help.Draw(&window);
        credits.Draw(&window);
        quit.Draw(&window);

        window.display();
    }

    return 0;
}