#include "MainMenu.h"

MainMenu::MainMenu(sf::RenderWindow& win){
    float x_offset = 550, y_offset_start = 250, y_offset = 100; //y_offset_start - startowe odsuniêcie od góry, y_offset - odstêp pomiêdzy kolejnymi przyciskami
    start = new Button("PLAY", x_offset, y_offset_start);
    highscore = new Button("Highscores", x_offset, y_offset + y_offset_start);
    help = new Button("Help", x_offset, 2 * y_offset + y_offset_start);
    credits = new Button("Credits", x_offset, 3 * y_offset + y_offset_start);
    quit = new Button("Exit", x_offset, 4 * y_offset + y_offset_start);
    snake = new Title("Snejk");
    window = &win;
}

void MainMenu::drawButtonsAndTitle() {
    snake->Draw(window);
    start->Draw(window);
    highscore->Draw(window);
    help->Draw(window);
    credits->Draw(window);
    quit->Draw(window);
}

void MainMenu::checkIfButtonWasClicked(int x, int y) {
    if (start->rectangle.getGlobalBounds().contains(x, y)) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            cout << "Graj" << endl;
        }
    }
    else if (highscore->rectangle.getGlobalBounds().contains(x, y)) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            cout << "Najlepsze wyniki" << endl;
        }
    }
    else if (help->rectangle.getGlobalBounds().contains(x, y)) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            cout << "Pomoc" << endl;
        }
    }
    else if (credits->rectangle.getGlobalBounds().contains(x, y)) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            cout << "Creditsy" << endl;
        }
    }
    else if (quit->rectangle.getGlobalBounds().contains(x, y)) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            cout << "Exit" << endl;
            window->close();
        }
    }
};