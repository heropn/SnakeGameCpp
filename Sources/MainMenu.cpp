#include "../Headers/MainMenu.h"

MainMenu::MainMenu(sf::RenderWindow& win, std::shared_ptr<MyFont> fontPtrTitle, std::shared_ptr<MyFont> fontPtrButtons)
	: window(&win), fontPtrTitle(fontPtrTitle), fontPtrButtons(fontPtrButtons), isInMainMenu(true)
{
	float x_offset = 550, y_offset_start = 250, y_offset = 100; //y_offset_start - startowe odsuniêcie od góry, y_offset - odstêp pomiêdzy kolejnymi przyciskami
	start = Button("PLAY", x_offset, y_offset_start, fontPtrButtons);
	highscore = Button("HIGHSCORES", x_offset, y_offset + y_offset_start, fontPtrButtons);
	help = Button("HELP", x_offset, 2 * y_offset + y_offset_start, fontPtrButtons);
	credits = Button("CREDITS", x_offset, 3 * y_offset + y_offset_start, fontPtrButtons);
	quit = Button("EXIT", x_offset, 4 * y_offset + y_offset_start, fontPtrButtons);
	snake.SetFont(fontPtrTitle);
}

void MainMenu::DrawButtonsAndTitle() 
{
	snake.Draw(window);
	start.Draw(window);
	highscore.Draw(window);
	help.Draw(window);
	credits.Draw(window);
	quit.Draw(window);
}

void MainMenu::CheckIfButtonWasClicked(sf::Vector2i vec)
{
	sf::Vector2f vecF = { (float)vec.x, (float)vec.y };

	if (start.rectangle.getGlobalBounds().contains(vecF.x, vecF.y))
	{
		cout << "Graj" << endl;
		isInMainMenu = false;
	}
	else if (highscore.rectangle.getGlobalBounds().contains(vecF.x, vecF.y))
	{
		cout << "Najlepsze wyniki" << endl;
	}
	else if (help.rectangle.getGlobalBounds().contains(vecF.x, vecF.y))
	{
		cout << "Pomoc" << endl;
	}
	else if (credits.rectangle.getGlobalBounds().contains(vecF.x, vecF.y))
	{
		cout << "Creditsy" << endl;
	}
	else if (quit.rectangle.getGlobalBounds().contains(vecF.x, vecF.y))
	{
		cout << "Exit" << endl;
	}
};

bool MainMenu::IsInMainMenu()
{
	return isInMainMenu;
}

void MainMenu::SetIsInMainMenu(bool value)
{
	isInMainMenu = value;
}

MainMenu::~MainMenu()
{
	/*delete start;
	delete highscore;
	delete help;
	delete credits;
	delete quit;
	delete snake;*/
}