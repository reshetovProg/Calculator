#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class Field
{
private:
	sf::RectangleShape rectangle;
	sf::Font font;
	sf::Text text;
public:
	Field(float, float, std::string);
	void setPosition(float, float);
	sf::Text& getText();
	sf::RectangleShape& getField();
	void setField(std::string);
};

