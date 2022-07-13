#include "Button.h"
#include "Calculator.h"

Button::Button(float width, float height, std::string name)
	: rectangle(sf::Vector2f(width, height))
{
	if (!font.loadFromFile("resources/fonts/arial.ttf"))
	{
		//std::cout << "font not found";
	}
	text.setString(name);
	text.setFont(font);
	text.setFillColor(sf::Color::White);
	text.setCharacterSize(40);
	rectangle.setOutlineColor(sf::Color(20, 20, 20));
	rectangle.setOutlineThickness(2);
	rectangle.setFillColor(sf::Color(38, 38, 38));
}

void Button::setPosition(float x, float y)
{
	rectangle.setPosition(x, y);
	text.setPosition(x + 40, y + 22);
}



void Button::push(Field*& field)
{
	std::string str = text.getString();
	std::string strField = field->getText().getString();
	if (strField == "0") strField = "";
	strField += str;
	field->setField(strField);
	//std::cout << str << " push"<<std::endl;

}

sf::Text& Button::getText()
{
	return text;
	// TODO: вставьте здесь оператор return
}



sf::RectangleShape& Button::getButton()
{
	return rectangle;
	// TODO: вставьте здесь оператор return
}

sf::Vector2f Button::getPosition()
{
	return rectangle.getPosition();
}
