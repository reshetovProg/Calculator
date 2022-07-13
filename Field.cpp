#include "Field.h"

Field::Field(float width, float height, std::string name)
	: rectangle(sf::Vector2f(width, height))
{
	if (!font.loadFromFile("resources/fonts/arial.ttf"))
	{
		//std::cout << "font not found";
	}
	text.setString(name);
	text.setFont(font);
	text.setFillColor(sf::Color(38, 38, 38));
	text.setCharacterSize(40);
	rectangle.setOutlineColor(sf::Color(20, 20, 20));
	rectangle.setOutlineThickness(2);
	rectangle.setFillColor(sf::Color::White);
}

void Field::setPosition(float x, float y)
{
	rectangle.setPosition(x, y);
	text.setPosition(x+10, y);
}

sf::Text& Field::getText()
{
	return text;
}

sf::RectangleShape& Field::getField()
{
	return rectangle;
}

void Field::setField(std::string str)
{
	text.setString(str);
}
