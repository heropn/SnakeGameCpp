#include "..\Headers\HighScoreEntity.h"
#include <iostream>

HighScoreEntity::HighScoreEntity(int score, std::string name, std::shared_ptr<MyFont> fontPtr) 
	: score(score), name(name), fontPtr(fontPtr)
{
	SetUpText();
}

void HighScoreEntity::SetPosition(sf::Vector2f vec2)
{
	text.setPosition(vec2);
}

const sf::Text& HighScoreEntity::GetText() const
{
	return text;
}

const std::string& HighScoreEntity::GetName() const
{
	return name;
}

const int HighScoreEntity::GetScore() const
{
	return score;
}

void HighScoreEntity::SetUpText()
{
	text.setFont(*fontPtr);
	text.setString('0' + ". " + name + " - " + std::to_string(score));
	text.setCharacterSize(50);
	text.setFillColor(sf::Color::Color(25, 255, 142));
}

void HighScoreEntity::Draw(sf::RenderWindow* window)
{
	window->draw(text);
}

void HighScoreEntity::SetPositionInRanking(int position)
{
	text.setString(std::to_string(position) + ". " + name + " - " + std::to_string(score));
}