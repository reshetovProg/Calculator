#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Field.h"

class Button
{
private:
	sf::RectangleShape rectangle;
	sf::Font font;
	sf::Text text;
	bool status = false;
public:
	Button(float, float, std::string);
	void setPosition(float, float);
	sf::Text& getText();
	sf::RectangleShape& getButton();
	sf::Vector2f getPosition();
	void push(Field*&);
};

