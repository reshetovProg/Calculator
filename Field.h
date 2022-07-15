#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class Field
{
private:
	sf::RectangleShape rectangle;
	sf::Font font;
	sf::Text text;
	std::string num1;
	std::string num2;
	short operation=0;
	bool status=false;
	bool flag = false; //after = (true)

public:
	Field(float, float, std::string);
	void setFlag(bool);
	bool getFlag(void);
	void setStatus(bool);
	bool getStatus(void);
	void setPosition(float, float);
	void setNum1(std::string num);
	void setNum2(std::string num);
	void setOperation(short operation);
	short getOperation();
	std::string getNum1();
	std::string getNum2();

	sf::Text& getText();
	sf::RectangleShape& getField();
	void setField(std::string);
};

