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

void Field::setNum1(std::string num)
{
	num1 = num;
}

void Field::setStatus(bool st)
{
	status = st;
}

void Field::setFlag(bool st)
{
	flag = st;
}

void Field::setNum2(std::string num)
{
	num2 = num;
}

bool Field::getStatus()
{
	return status;
}

bool Field::getFlag()
{
	return flag;
}

void Field::setOperation(short operation)
{
	this->operation = operation;
}

short Field::getOperation()
{
	return operation;
}

std::string Field::getNum1()
{
	return num1;
}

std::string Field::getNum2()
{
	return num2;
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
